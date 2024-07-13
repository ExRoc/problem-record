#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 500000 + 100;
int n, k1, k2;
LL ans;
LL num[maxn];
int bit[maxn][64];

bool isAllTheSame(int l, int r, int dig) {
    return bit[r][dig] - bit[l - 1][dig] == 0 ||
           bit[r][dig] - bit[l - 1][dig] == r - l + 1;
}

LL cal(int l, int r) {
    LL ret = 0;
    for (int i = 0; i < 62; ++i) {
        if (!isAllTheSame(l, r, i)) {
            ret |= (1LL << i);
        }
    }
    return ret;
}

bool judge(int l, int r) {
    for (int i = 0; i < k1; ++i) {
        if (!isAllTheSame(l, r, i)) {
            return false;
        }
    }
    bool flag = false;
    for (int i = k1; i < k2; ++i) {
        if (!isAllTheSame(l, r, i)) {
            flag = true;
            break;
        }
    }
    if (!flag) {
        return false;
    }
    for (int i = k2; i < 62; ++i) {
        if (!isAllTheSame(l, r, i)) {
            return false;
        }
    }
    return true;
}

LL solve(int l, int k) {
    int high = n + 1;
    int low = l - 1;
    int mid;
    while (high - low > 1) {
        mid = (high + low) >> 1;
        if (cal(l, mid) < (1LL << k)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> k1 >> k2;
    if (k1 >= 62) {
        cout << 0 << endl;
        return 0;
    }
    k2 = min(k2, 62);
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
        memcpy(bit[i], bit[i - 1], sizeof(bit[i]));
        for (int j = 0; j < 62; ++j) {
            if ((num[i] >> j) & 1) {
                ++bit[i][j];
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        ans += solve(i, k2) - solve(i, k1);
    }
    cout << ans << endl;

    return 0;
}
