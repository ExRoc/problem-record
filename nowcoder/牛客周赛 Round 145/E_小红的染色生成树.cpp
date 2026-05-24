#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int cnt_;
    vector<int> parent_;

    explicit DSU(int n) : cnt_(n), parent_(n + 1) {
        for (int i = 0; i <= n; ++i) {
            parent_[i] = i;
        }
    }

    int Find(int x) {
        return parent_[x] == x ? x : parent_[x] = Find(parent_[x]);
    }

    void Unite(int x, int y) {
        x = Find(x);
        y = Find(y);
        if (x != y) {
            --cnt_;
            parent_[y] = x;
        }
    }

    bool Same(int x, int y) { return Find(x) == Find(y); }
};

struct Node {
    int u, v, w;

    Node() {}

    Node(int u, int v, int w) : u(u), v(v), w(w) {}

    bool operator<(const Node& other) const { return w < other.w; }
};

vector<Node> solve(int c1, int c2, int n, const vector<Node>& nodes) {
    vector<Node> chose;
    for (const Node& node : nodes) {
        if (node.w == c1 || node.w == c2) {
            chose.push_back(node);
        }
    }
    sort(chose.begin(), chose.end());
    DSU dsu(n + 1);
    int cnt = n;
    int l = 0;
    int r = chose.size() - 1;
    int flag = 0;
    set<int> setw;
    vector<Node> ans;
    while (l <= r) {
        if (flag == 0) {
            if (dsu.Same(chose[l].u, chose[l].v)) {
                ++l;
                continue;
            }
            --cnt;
            dsu.Unite(chose[l].u, chose[l].v);
            flag = 1;
            setw.insert(chose[l].w);
            ans.push_back(chose[l]);
            ++l;
            continue;
        }
        if (dsu.Same(chose[r].u, chose[r].v)) {
            --r;
            continue;
        }
        --cnt;
        dsu.Unite(chose[r].u, chose[r].v);
        flag = 0;
        setw.insert(chose[r].w);
        ans.push_back(chose[r]);
        --r;
    }

    if (cnt == 1 && (int)setw.size() == 2) {
        return ans;
    }
    return vector<Node>();
}

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<Node> nodes(m);
    for (int i = 0; i < m; ++i) {
        cin >> nodes[i].u >> nodes[i].v >> nodes[i].w;
    }
    vector<Node> ans;
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            ans = solve(i, j, n, nodes);
            if (!ans.empty()) {
                break;
            }
        }
        if (!ans.empty()) {
            break;
        }
    }
    if (ans.empty()) {
        cout << -1 << '\n';
        return 0;
    }
    for (Node& node : ans) {
        cout << node.u << " " << node.v << '\n';
    }

    return 0;
}