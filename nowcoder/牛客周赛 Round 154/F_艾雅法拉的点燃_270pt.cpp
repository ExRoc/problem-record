#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const long long INF = 0x3f3f3f3f3f3f3f3f;
    int n;
    long long x, y;
    cin >> n >> x >> y;
    vector<vector<vector<long long>>> dp(
        2, vector<vector<long long>>(51, vector<long long>(51, INF)));
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        int now = (i & 1);
        int pre = (now ^ 1);
        for (int j = 0; j <= 50; ++j) {
            for (int k = 0; k <= 50; ++k) {
                dp[now][j][k] = INF;
            }
        }
        for (int j = 0; j <= 50; ++j) {
            for (int k = 0; k <= 50; ++k) {
                if (dp[pre][j][k] == INF) {
                    continue;
                }
                for (int l = 0; l <= 50; ++l) {
                    int nowJ = max(0, j - l);
                    int nowK = max(0, k - 2 * l);
                    int nowL = max(0, a - l);
                    dp[now][nowK][nowL] = min(
                        {dp[now][nowK][nowL], dp[pre][j][k] + x * nowJ + y * l,
                         dp[pre][j][k] + x * (j + k - nowK + a - nowL)});
                }
                for (int l = 0; l <= 25; ++l) {
                    int nowK = max(0, k - l);
                    int nowL = max(0, a - 2 * l);
                    dp[now][nowK][nowL] =
                        min({dp[now][nowK][nowL], dp[pre][j][k] + y * l + x * j,
                             dp[pre][j][k] + x * (j + k - nowK + a - nowL)});
                }
            }
        }
        for (int j = 50; j >= 0; --j) {
            for (int k = 50; k >= 0; --k) {
                if (j + 1 <= 50) {
                    dp[now][j][k] = min(dp[now][j][k], dp[now][j + 1][k] + x);
                }
                if (k + 1 <= 50) {
                    dp[now][j][k] = min(dp[now][j][k], dp[now][j][k + 1] + x);
                }
            }
        }
    }
    long long ans = INF;
    for (int j = 0; j <= 50; ++j) {
        for (int k = 0; k <= 50; ++k) {
            if (dp[n & 1][j][k] == INF) {
                continue;
            }
            ans = min(ans, dp[n & 1][j][k] + x * (j + k));
        }
    }
    cout << ans << '\n';

    return 0;
}