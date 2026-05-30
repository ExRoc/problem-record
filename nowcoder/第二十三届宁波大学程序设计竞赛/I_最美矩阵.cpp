#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> ans(n, vector<int>(n));
        int x = 0;
        int y = 0;
        long long sum = 0;
        for (int i = n * n; i >= 1; --i) {
            ans[x][y] = i;
            if (x + m <= n && y + m <= n) {
                sum += i;
            }
            if (x <= y) {
                ++y;
            } else {
                ++x;
            }
            if (x == n) {
                x = y + 1;
                y = x;
            } else if (y == n) {
                x = x + 1;
                y = x - 1;
            }
        }
        cout << sum << '\n';
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << ans[i][j] << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}