#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 300000 + 100;
int T, n, k;
LL num[maxn];
LL dp[maxn][15];

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
        }
        for (int i = 1; i <= n; ++i) {
            int top = min(k, i - 1);
            for (int j = 0; j <= top; ++j) {
                LL mn = num[i];
                dp[i][j] = dp[i - 1][j] + num[i];
                for (int k = 1; k <= j; ++k) {
                    mn = min(mn, num[i - k]);
                    dp[i][j] =
                        min(dp[i][j], dp[i - k - 1][j - k] + mn * (k + 1));
                }
            }
            for (int j = top + 1; j <= k; ++j) {
                dp[i][j] = dp[i][j - 1];
            }
        }
        cout << dp[n][k] << endl;
    }

    return 0;
}
