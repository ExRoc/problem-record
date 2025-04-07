#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int n;
LL m, ans;
LL p[maxn];

// 计算增量最大为 x 的情况下，能买多少个价格为 p 的产品
LL cal(LL x, LL p) {
    x /= p;
    if (x == 0) {
        return 0;
    }
    if (x % 2 == 0) {
        --x;
    }
    return (x + 1) / 2;
}

// 判断 k * k * p > m
bool judge3(LL k, LL p, LL m) {
    if (k == 0) {
        return false;
    }
    if (k > m / k) {
        return true;
    }
    if (k * k > m / p) {
        return true;
    }
    return k * k * p > m;
}

bool judge(LL x) {
    LL mm = m;
    LL cntK = 0;
    for (int i = 1; i <= n; ++i) {
        LL k = cal(x, p[i]);
        if (judge3(k, p[i], mm)) {
            return false;
        }
        mm -= k * k * p[i];
        cntK += k;
    }
    ans = max(ans, cntK);
    return true;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    LL high = m + 1;
    LL low = 0;
    LL mid;
    while (high - low > 1) {
        mid = (high + low) >> 1;
        if (judge(mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }

    LL mm = m;
    LL cntK = 0;
    for (int i = 1; i <= n; ++i) {
        LL k = cal(low + 1, p[i]);
        if (judge3(k, p[i], mm)) {
            break;
        }
        mm -= k * k * p[i];
        cntK += k;
    }
    ans = max(ans, cntK);

    cout << ans << endl;

    return 0;
}
