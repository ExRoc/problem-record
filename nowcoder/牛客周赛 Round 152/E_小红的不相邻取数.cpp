#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
    for (int i = 1; i <= n; ++i) {
        if (a[i] < 0) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = LONG_LONG_MIN;
            continue;
        }
        dp[i][0] = max(dp[i - 1][0] + b[i] / 2 * a[i],
                       dp[i - 1][1] + (b[i] - 1) / 2 * a[i]);
        dp[i][1] = max(dp[i - 1][0] + (b[i] + 1) / 2 * a[i],
                       dp[i - 1][1] + b[i] / 2 * a[i]);
    }
    cout << max(dp[n][0], dp[n][1]) << '\n';

    return 0;
}