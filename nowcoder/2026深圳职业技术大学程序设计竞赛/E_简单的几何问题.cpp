#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> num(n + 2, vector<int>(m + 2, 0));
        for (int i = 1; i <= n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                num[i][j + 1] = s[j] - '0';
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (num[i][j] == 0) {
                    continue;
                }
                for (int k = 0; k < 4; ++k) {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if (num[x][y] == 0) {
                        ++ans;
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}