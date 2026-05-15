#include <bits/stdc++.h>
using namespace std;

void dfs1(int root, int fa, vector<vector<int>>& G, vector<int>& ans) {
    ans[root] = 0;
    for (int pos : G[root]) {
        if (pos == fa) {
            continue;
        }
        dfs1(pos, root, G, ans);
        if (ans[pos] == 0) {
            ans[root] = 1;
        }
    }
}

void dfs2(int root, int fa, int fromFa, vector<vector<int>>& G,
          vector<int>& ans) {
    set<int> st;
    if (fromFa == 0) {
        ans[root] = 1;
        st.insert(fa);
    }
    for (int pos : G[root]) {
        if (pos == fa) {
            continue;
        }
        if (ans[pos] == 0) {
            st.insert(pos);
        }
    }
    for (int pos : G[root]) {
        if (pos == fa) {
            continue;
        }
        int fromRoot = 0;
        if (st.size() >= 2) {
            fromRoot = 1;
        } else if ((int)st.size() == 1) {
            if (st.find(pos) == st.end()) {
                fromRoot = 1;
            }
        }
        dfs2(pos, root, fromRoot, G, ans);
    }
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> G(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> ans(n + 1);
    dfs1(1, 1, G, ans);
    dfs2(1, 1, 1, G, ans);
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == 1) {
            cout << "Alice" << '\n';
        } else {
            cout << "Bob" << '\n';
        }
    }

    return 0;
}