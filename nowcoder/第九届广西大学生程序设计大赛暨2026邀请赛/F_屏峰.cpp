#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, m, q, s, t;
        cin >> n >> m >> q >> s >> t;
        vector<vector<int>> G(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        queue<int> que;
        vector<int> color(n + 1, -1);
        que.push(s);
        color[s] = 0;
        bool flag = false;
        while (!que.empty()) {
            int tmp = que.front();
            que.pop();
            for (int pos : G[tmp]) {
                if (color[pos] == -1) {
                    color[pos] = color[tmp] ^ 1;
                    que.push(pos);
                } else {
                    if (color[tmp] == color[pos]) {
                        flag = true;
                    }
                }
            }
        }
        while (q--) {
            int a, b;
            cin >> a >> b;
            if (flag) {
                if (color[a] == -1 || color[b] == -1) {
                    cout << "No" << '\n';
                } else {
                    cout << "Yes" << '\n';
                }
            } else {
                if (color[a] == 0 && color[b] == 1) {
                    cout << "Yes" << '\n';
                } else {
                    cout << "No" << '\n';
                }
            }
        }
    }

    return 0;
}