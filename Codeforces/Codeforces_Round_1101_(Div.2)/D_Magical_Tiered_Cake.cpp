#include <bits/stdc++.h>
using namespace std;

struct Node {
    int a, idx;

    Node() {}

    Node(int a, int idx) : a(a), idx(idx) {}

    bool operator<(const Node& other) const { return false; }
};

void dfs(const vector<Node>& nodes, int idx, int from, int cross, int to,
         vector<vector<int>>& ans) {
    if (idx == 0) {
        return;
    }
    if (nodes[idx].a == 0) {
        dfs(nodes, idx - 1, from, to, cross, ans);
        ans.push_back({idx, from, to});
        dfs(nodes, idx - 1, cross, from, to, ans);
        return;
    }
    dfs(nodes, idx - nodes[idx].a - 1, from, to, cross, ans);
    ans.push_back({idx, from, to});
    dfs(nodes, idx - nodes[idx].a - 1, cross, to, from, ans);
    dfs(nodes, idx - 1, from, cross, to, ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<Node> nodes(n + 1);
        bool flag = true;
        for (int i = 1; i <= n; ++i) {
            cin >> nodes[i].a;
            nodes[i].idx = i;
            if (nodes[i].a >= nodes[i].idx) {
                flag = false;
            }
        }
        if (!flag) {
            cout << "NO" << '\n';
            continue;
        }
        vector<vector<int>> ans;
        dfs(nodes, n, 1, 2, 3, ans);
        cout << "YES" << '\n';
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << ans[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}