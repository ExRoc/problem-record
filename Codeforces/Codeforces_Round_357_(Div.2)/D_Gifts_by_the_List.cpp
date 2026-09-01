#include <bits/stdc++.h>
using namespace std;

struct Node1 {
    int pos, depth;

    Node1() {}

    Node1(int pos, int depth) : pos(pos), depth(depth) {}

    bool operator<(const Node1& other) const {
        return depth == other.depth ? pos < other.pos : depth > other.depth;
    }
};

struct Node2 {
    int pos, idx;

    Node2() {}

    Node2(int pos, int idx) : pos(pos), idx(idx) {}

    bool operator<(const Node2& other) const {
        return idx == other.idx ? pos < other.pos : idx < other.idx;
    }
};

void dfs1(int root, int depth, const vector<vector<int>>& G,
          vector<int>& depths) {
    depths[root] = depth;
    for (int pos : G[root]) {
        dfs1(pos, depth + 1, G, depths);
    }
}

bool dfs2(int root, const vector<vector<int>>& G, const vector<int>& a,
          const vector<int>& idxs, set<Node2>& st) {
    if (idxs[root] != 0) {
        st.insert(Node2(root, idxs[root]));
    }
    if (a[root] != st.begin()->pos) {
        return false;
    }
    for (int pos : G[root]) {
        if (!dfs2(pos, G, a, idxs, st)) {
            return false;
        }
    }
    st.erase(Node2(root, idxs[root]));
    return true;
}

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    vector<int> degin(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int p, q;
        cin >> p >> q;
        G[p].push_back(q);
        ++degin[q];
    }
    vector<int> depths(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (degin[i] == 0) {
            dfs1(i, 0, G, depths);
        }
    }
    set<Node1> st;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        st.insert(Node1(a[i], depths[a[i]]));
    }
    vector<int> idxs(n + 1, 0);
    int idx = 1;
    for (const Node1& node : st) {
        idxs[node.pos] = idx++;
    }
    set<Node2> st2;
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        if (degin[i] == 0) {
            if (!dfs2(i, G, a, idxs, st2)) {
                flag = false;
                break;
            }
        }
    }
    if (!flag) {
        cout << -1 << '\n';
        return 0;
    }
    cout << st.size() << '\n';
    for (const Node1& node : st) {
        cout << node.pos << '\n';
    }

    return 0;
}