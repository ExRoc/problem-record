#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int m;
        cin >> m;
        vector<vector<long long>> dp(m + 1, vector<long long>(6, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= 5; ++j) {
                dp[i][j] = dp[i - 1][j] + (m - i);
                if (j > 0 && j * 3 <= i) {
                    dp[i][j] = max(dp[i][j], dp[i - 3][j - 1] +
                                                 1LL * (i - j * 3) * (m - i));
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i <= 5; ++i) {
            ans = max(ans, dp[m][i]);
        }
        cout << ans << '\n';
    }

    return 0;
}