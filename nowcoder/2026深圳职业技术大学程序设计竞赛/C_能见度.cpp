#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> h(n + 1, vector<int>(m + 1, 0));
    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int x1, y1, x2, y2, k;
            cin >> x1 >> y1 >> x2 >> y2 >> k;
            for (int i = x1; i <= x2; ++i) {
                for (int j = y1; j <= y2; ++j) {
                    h[i][j] += k;
                }
            }
        } else {
            int x, y;
            cin >> x >> y;
            int xx = x;
            int ans = 0;
            while (xx >= 1 && h[xx][y] <= h[x][y]) {
                ++ans;
                --xx;
            }
            xx = x + 1;
            while (xx <= n && h[xx][y] <= h[x][y]) {
                ++ans;
                ++xx;
            }
            int yy = y - 1;
            while (yy >= 1 && h[x][yy] <= h[x][y]) {
                ++ans;
                --yy;
            }
            yy = y + 1;
            while (yy <= m && h[x][yy] <= h[x][y]) {
                ++ans;
                ++yy;
            }
            cout << ans << ' ';
        }
    }

    return 0;
}