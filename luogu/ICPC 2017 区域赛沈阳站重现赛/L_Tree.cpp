#include <bits/stdc++.h>
using namespace std;

void dfs(int root, int fa, const vector<vector<int>>& G, int d,
         vector<int>& depth, vector<int>& son) {
    son[root] = 1;
    depth[root] = d;
    for (int pos : G[root]) {
        if (pos == fa) {
            continue;
        }
        dfs(pos, root, G, d + 1, depth, son);
        son[root] += son[pos];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> G(n + 1);
        for (int i = 1; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        vector<int> depth(n + 1);
        vector<int> son(n + 1);
        dfs(1, 1, G, 0, depth, son);
        int root1 = 1;
        for (int i = 1; i <= n; ++i) {
            if (depth[i] > depth[root1]) {
                root1 = i;
            }
        }
        dfs(root1, root1, G, 0, depth, son);
        int root2 = root1;
        for (int i = 1; i <= n; ++i) {
            if (son[i] >= k && depth[i] > depth[root2]) {
                root2 = i;
            }
        }
        dfs(root2, root2, G, 0, depth, son);
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (son[i] >= k) {
                ++ans;
            }
        }
        cout << ans - 1 << '\n';
    }

    return 0;
}