#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> degin(n + 1, 0);
        vector<vector<int>> G(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            ++degin[v];
        }
        priority_queue<int, vector<int>, greater<int>> que;
        for (int i = 1; i <= n; ++i) {
            if (degin[i] == 0) {
                que.push(i);
            }
        }
        vector<int> ans;
        while (!que.empty()) {
            int tmp = que.top();
            ans.push_back(tmp);
            que.pop();
            for (int pos : G[tmp]) {
                --degin[pos];
                if (degin[pos] == 0) {
                    que.push(pos);
                }
            }
        }
        if ((int)ans.size() == n) {
            cout << "Yes" << '\n';
            for (int i = 0; i < n; ++i) {
                cout << ans[i] << ' ';
            }
            cout << '\n';
        } else {
            cout << "No" << '\n';
        }
    }

    return 0;
}