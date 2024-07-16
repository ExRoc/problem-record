#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100;
int T, n, m, nm;
LL MOD;
LL dp[maxn * maxn][maxn][maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n >> m >> MOD;
        nm = n * m;
        dp[1][1][1] = nm;
        for (int i = 2; i <= nm; ++i) {
            int topj = min(n, i);
            for (int j = 1; j <= topj; ++j) {
                int topk = min(m, i);
                for (int k = 1; k <= topk; ++k) {
                    dp[i][j][k] = 0;
                    if (j * k < i) {
                        continue;
                    }
                    dp[i][j][k] = (dp[i - 1][j - 1][k] * (n - j + 1) * k +
                                   dp[i - 1][j][k - 1] * (m - k + 1) * j +
                                   dp[i - 1][j][k] * (j * k - i + 1)) %
                                  MOD;
                }
            }
        }
        cout << dp[nm][n][m] << endl;
    }

    return 0;
}
