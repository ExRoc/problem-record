#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 2) {
            cout << -1 << '\n';
            continue;
        }
        int x = 0;
        int y = 0;
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 1; i <= n * n; ++i) {
            ans[x][y] = i;
            if (x != n - 1 && y != n - 1) {
                ++x;
                ++y;
                continue;
            }
            if (x == n - 1) {
                y = x - y + 1;
                x = 0;
            } else {
                x = y - x;
                y = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << ans[i][j] << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}