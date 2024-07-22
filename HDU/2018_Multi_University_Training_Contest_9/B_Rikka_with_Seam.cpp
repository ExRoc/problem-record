#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 2000 + 100;
const int MOD = 998244353;
int T, n, m, k;
char str[maxn][maxn];
int dp[maxn][maxn], sub[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; ++i) {
            scanf("%s", str[i] + 1);
        }
        for (int j = 1; j <= m; ++j) {
            dp[1][j] = j;
            sub[1][j] = sub[1][j - 1];
            if (str[1][j] == str[1][j - 1]) {
                ++sub[1][j];
            }
        }

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int l = max(1, j - k);
                int r = min(m, j + k);
                dp[i][j] = (((dp[i - 1][r] - dp[i - 1][l - 1]) % MOD -
                             (sub[i - 1][r] - sub[i - 1][l]) % MOD) %
                                MOD +
                            MOD) %
                           MOD;
                if (str[i][j] != str[i][j - 1]) {
                    sub[i][j] = 0;
                    continue;
                }
                r = min(m, j + k - 1);
                sub[i][j] = (((dp[i - 1][r] - dp[i - 1][l - 1]) % MOD -
                              (sub[i - 1][r] - sub[i - 1][l]) % MOD) %
                                 MOD +
                             MOD) %
                            MOD;
            }
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
                sub[i][j] = (sub[i][j] + sub[i][j - 1]) % MOD;
            }
        }
        printf("%d\n", ((dp[n][m] - sub[n][m]) % MOD + MOD) % MOD);
    }

    return 0;
}
