#include <bits/stdc++.h>
using namespace std;

int solve(int x, int y, const vector<string>& G, const vector<string>& p) {
    int n = G.size();
    int m = G[0].size();
    int pn = p.size();
    int pm = p[0].size();
    int ans = 0;
    for (int d = 1; d <= 5; ++d) {
        int dpn = d * pn;
        int dpm = d * pm;
        // 右下
        if (x + dpn <= n && y + dpm <= m) {
            bool flag = true;
            for (int i = 0; i < dpn; ++i) {
                for (int j = 0; j < dpm; ++j) {
                    int ii = i / d;
                    int jj = j / d;
                    if (p[ii][jj] == '.') {
                        continue;
                    }
                    if (G[x + i][y + j] != '#') {
                        flag = false;
                        break;
                    }
                }
                if (!flag) {
                    break;
                }
            }
            if (flag) {
                ++ans;
            }
        }
        // 左下
        if (y - dpn >= -1 && x + dpm <= n) {
            bool flag = true;
            for (int i = 0; i < dpn; ++i) {
                for (int j = 0; j < dpm; ++j) {
                    int ii = i / d;
                    int jj = j / d;
                    if (p[ii][jj] == '.') {
                        continue;
                    }
                    if (G[x + j][y - i] != '#') {
                        flag = false;
                        break;
                    }
                }
                if (!flag) {
                    break;
                }
            }
            if (flag) {
                ++ans;
            }
        }
        // 左上
        if (x - dpn >= -1 && y - dpm >= -1) {
            bool flag = true;
            for (int i = 0; i < dpn; ++i) {
                for (int j = 0; j < dpm; ++j) {
                    int ii = i / d;
                    int jj = j / d;
                    if (p[ii][jj] == '.') {
                        continue;
                    }
                    if (G[x - i][y - j] != '#') {
                        flag = false;
                        break;
                    }
                }
                if (!flag) {
                    break;
                }
            }
            if (flag) {
                ++ans;
            }
        }
        // 右上
        if (x - dpm >= -1 && y + dpn <= m) {
            bool flag = true;
            for (int i = 0; i < dpn; ++i) {
                for (int j = 0; j < dpm; ++j) {
                    int ii = i / d;
                    int jj = j / d;
                    if (p[ii][jj] == '.') {
                        continue;
                    }
                    if (G[x - j][y + i] != '#') {
                        flag = false;
                        break;
                    }
                }
                if (!flag) {
                    break;
                }
            }
            if (flag) {
                ++ans;
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<string> G(n);
    for (int i = 0; i < n; ++i) {
        cin >> G[i];
    }
    vector<vector<string>> p = {{"#.#.#", "#.#.#", ".#.#."},
                                {"###", ".#.", ".#."},
                                {"#.#", "#.#", "###"}};

    vector<int> ans(3);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 3; ++k) {
                ans[k] += solve(i, j, G, p[k]);
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        cout << ans[i] << " ";
    }
    cout << '\n';

    return 0;
}