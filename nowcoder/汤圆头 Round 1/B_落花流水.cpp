#include <bits/stdc++.h>
using namespace std;

int findNext(const vector<long long>& a, int l, int m) {
    int r = l;
    while (r <= m && a[r] != -1) {
        ++r;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<long long>> a(n + 1, vector<long long>(m + 1));
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, -1));
    dp[0][1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
        int l = 1;
        int r = 0;
        while (l <= m) {
            if (a[i][l] == -1) {
                ++l;
                r = l;
                continue;
            }
            int next = findNext(a[i], l, m);
            int r = next - 1;
            long long sum = 0;
            for (int j = l; j <= r; ++j) {
                sum += a[i][j];
            }
            long long mx = -1;
            for (int j = l; j <= r; ++j) {
                if (dp[i - 1][j] != -1) {
                    mx = max(mx, dp[i - 1][j] + sum);
                }
            }
            for (int j = l; j <= r; ++j) {
                dp[i][j] = mx;
            }
            l = r = next;
        }
    }
    cout << dp[n][m] << '\n';

    return 0;
}