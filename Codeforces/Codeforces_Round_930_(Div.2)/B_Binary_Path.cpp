#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int T, n, idx;
LL dp[2][maxn];
char ans[maxn];
char str[2][maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        idx = 0;
        cin >> n;
        cin >> (str[0] + 1) >> (str[1] + 1);
        for (int i = 0; i < 2; ++i) {
            memset(dp[i] + 1, 0, sizeof(LL) * n);
        }
        ans[idx++] = str[0][1];
        for (int i = 1; i < n; ++i) {
            if (str[0][i + 1] <= str[1][i]) {
                ans[idx++] = str[0][i + 1];
            } else {
                break;
            }
        }
        for (int i = idx; i <= n; ++i) {
            ans[idx++] = str[1][i];
        }
        ans[idx] = '\0';
        cout << ans << endl;
        dp[0][1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (str[0][i] == ans[i - 1]) {
                dp[0][i] = 1;
            } else {
                break;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (str[1][i] == ans[i]) {
                dp[1][i] = dp[0][i] + dp[1][i - 1];
            }
        }
        cout << dp[1][n] << endl;
    }

    return 0;
}
