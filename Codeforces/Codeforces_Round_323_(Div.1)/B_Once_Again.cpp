#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
int n, T, idx, cnt;
int num[maxn], dp[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> T;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
    }
    int nT = min(n, T);
    for (int i = 1; i <= nT; ++i) {
        for (int j = 1; j <= n; ++j) {
            idx = upper_bound(dp, dp + cnt, num[j]) - dp;
            if (idx < cnt) {
                dp[idx] = num[j];
            } else {
                dp[cnt++] = num[j];
            }
        }
    }
    if (T <= n) {
        cout << cnt << endl;
        return 0;
    }
    LL tmp = cnt;
    for (int i = 1; i <= n; ++i) {
        idx = upper_bound(dp, dp + cnt, num[i]) - dp;
        if (idx < cnt) {
            dp[idx] = num[i];
        } else {
            dp[cnt++] = num[i];
        }
    }
    cout << tmp + (T - n) * (cnt - tmp) << endl;

    return 0;
}
