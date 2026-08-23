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

struct Edge {
    int u, v;
    long long w;

    Edge() {}

    Edge(int u, int v, long long w) : u(u), v(v), w(w) {}

    bool operator<(const Edge& other) const { return w < other.w; }
};

long long solve(int n, int k, int mask, const vector<vector<Edge>>& towns,
                vector<Edge> edges, const vector<long long>& c) {
    long long ans = 0;
    for (int i = 0; i < k; ++i) {
        if (((mask >> i) & 1) == 1) {
            ans += c[i];
            for (const Edge& edge : towns[i]) {
                edges.push_back(edge);
            }
        }
    }
    DSU dsu(k + n);
    sort(edges.begin(), edges.end());
    for (const Edge& edge : edges) {
        if (!dsu.Same(edge.u, edge.v)) {
            ans += edge.w;
            dsu.Unite(edge.u, edge.v);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    vector<Edge> newEdges;
    for (const Edge& edge : edges) {
        if (!dsu.Same(edge.u, edge.v)) {
            newEdges.push_back(edge);
            dsu.Unite(edge.u, edge.v);
        }
    }
    swap(edges, newEdges);

    vector<long long> c(k);
    vector<vector<Edge>> towns(k);
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
        for (int j = 1; j <= n; ++j) {
            long long a;
            cin >> a;
            towns[i].push_back(Edge(i + n + 1, j, a));
        }
    }
    int maskTop = (1 << k);
    const long long INF = 0x3f3f3f3f3f3f3f3f;
    long long ans = INF;
    for (int i = 0; i < maskTop; ++i) {
        ans = min(ans, solve(n, k, i, towns, edges, c));
    }
    cout << ans << '\n';

    return 0;
}