#include <bits/stdc++.h>
using namespace std;

void dfs(int root, int fa, vector<int>& w, vector<vector<int>>& G,
         vector<set<int>>& st, vector<int>& ans) {
    int n = w.size() - 1;
    for (int pos : G[root]) {
        if (pos == fa) {
            continue;
        }
        dfs(pos, root, w, G, st, ans);
        if (st[root].empty() || *(st[root].begin()) > *(st[pos].begin())) {
            swap(st[root], st[pos]);
            ans[root] = ans[pos];
        }
    }
    st[root].insert(w[root]);
    for (int i = ans[root]; i <= n; ++i) {
        if (st[root].find(i) == st[root].end()) {
            ans[root] = i;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> w(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> w[i];
        }
        vector<vector<int>> G(n + 1);
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> ans(n + 1);
        vector<set<int>> st(n + 1);
        dfs(1, 1, w, G, st, ans);
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}