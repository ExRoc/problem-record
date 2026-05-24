#include <bits/stdc++.h>
using namespace std;

class DSU {
   public:
    explicit DSU(int n) : parent_(n) {
        for (int i = 0; i < n; ++i) {
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
            parent_[y] = x;
        }
    }

    bool Same(int x, int y) { return Find(x) == Find(y); }

   private:
    std::vector<int> parent_;
};

struct Node {
    int u, v, dis;

    Node() {}

    Node(int u, int v, int dis) : u(u), v(v), dis(dis) {}

    bool operator<(const Node& other) const { return dis < other.dis; }
};

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<Node> nodes;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        nodes.push_back(Node(0, i, a));
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        nodes.push_back(Node(u, v, w));
    }
    sort(nodes.begin(), nodes.end());
    DSU dsu(n + 1);
    long long ans = 0;
    for (Node& node : nodes) {
        if (!dsu.Same(node.u, node.v)) {
            dsu.Unite(node.u, node.v);
            ans += node.dis;
        }
    }
    cout << ans << '\n';

    return 0;
}