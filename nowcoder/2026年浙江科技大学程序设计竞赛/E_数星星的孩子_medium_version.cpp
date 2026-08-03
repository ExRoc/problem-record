#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> bits(n, vector<int>(30, 0));
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            for (int j = 0; j <= 29; ++j) {
                bits[i][j] = ((a >> j) & 1);
            }
        }
        long long ans = 0;
        for (int i = 0; i <= 29; ++i) {
            vector<long long> cnt(2, 0);
            for (int j = 0; j < n; ++j) {
                ++cnt[bits[j][i]];
                ans += cnt[1 - bits[j][i]];
            }
        }
        vector<vector<vector<vector<int>>>> cnt(
            30, vector<vector<vector<int>>>(
                    30, vector<vector<int>>(2, vector<int>(2, 0))));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= 29; ++j) {
                for (int k = 0; k <= 29; ++k) {
                    ++cnt[j][k][bits[i][j]][bits[i][k]];
                }
            }
        }
        for (int i = 0; i < 29; ++i) {
            for (int j = i + 1; j <= 29; ++j) {
                ans += 2LL * cnt[i][j][0][0] * cnt[i][j][1][1] +
                       2LL * cnt[i][j][0][1] * cnt[i][j][1][0];
            }
        }
        cout << ans << '\n';
    }

    return 0;
}