#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = dp[i - 1][j] + a[i];
                if (i >= 2 && j >= 1) {
                    dp[i][j] =
                        max(dp[i][j], dp[i - 2][j - 1] + 1LL * a[i - 1] * a[i]);
                }
            }
        }
        long long ans = LONG_LONG_MIN;
        for (int i = 0; i <= k; ++i) {
            ans = max(ans, dp[n][i]);
        }
        cout << ans << '\n';
    }

    return 0;
}