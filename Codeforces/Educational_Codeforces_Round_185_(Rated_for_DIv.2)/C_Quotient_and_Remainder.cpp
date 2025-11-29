#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int T, n;
LL k;
LL q[maxn], r[maxn];

bool cmp(int a, int b) {
    return a > b;
}

bool judge(int i, int j) {
    LL y = r[j] + 1;
    // LL x = y * q[i] + r[j] <= k && y < x
    return q[i] <= (k - r[j]) / y && q[i] * y + r[j] > y;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> q[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> r[i];
        }
        sort(q + 1, q + 1 + n, cmp);
        sort(r + 1, r + 1 + n);
        int ans = 0;
        int i = 1;
        int j = 1;
        while (i <= n && j <= n) {
            if (judge(i, j)) {
                ++i;
                ++j;
                ++ans;
            } else {
                ++i;
            }
        }
        cout << ans << endl;
    }

    return 0;
}