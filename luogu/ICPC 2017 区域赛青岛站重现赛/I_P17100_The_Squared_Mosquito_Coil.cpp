#include <bits/stdc++.h>
using namespace std;

bool in(int x, int y, int n) { return x >= 0 && x < n && y >= 0 && y < n; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> ans(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i].push_back(' ');
            }
        }
        int x = 0, y = 0;
        ans[x][y] = '#';
        int blockCnt = 0;
        int idx = 0;
        while (blockCnt < 10) {
            int xx = x + dir[idx][0];
            int yy = y + dir[idx][1];
            if (!in(xx, yy, n)) {
                idx = (idx + 1) % 4;
                ++blockCnt;
                continue;
            }
            if (ans[xx][yy] == '#') {
                ++blockCnt;
                idx = (idx + 1) % 4;
                continue;
            }
            int cnt = 0;
            for (int i = 0; i < 4; ++i) {
                int xxx = xx + dir[i][0];
                int yyy = yy + dir[i][1];
                if (in(xxx, yyy, n) && ans[xxx][yyy] == '#') {
                    ++cnt;
                }
            }
            if (cnt > 1) {
                idx = (idx + 1) % 4;
                ++blockCnt;
                continue;
            }
            blockCnt = 0;
            ans[xx][yy] = '#';
            x = xx;
            y = yy;
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << '\n';
        }
    }

    return 0;
}