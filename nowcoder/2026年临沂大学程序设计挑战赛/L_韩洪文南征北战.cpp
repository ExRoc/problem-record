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
    int u, v, w;

    Edge() {}

    Edge(int u, int v, int w) : u(u), v(v), w(w) {}

    bool operator<(const Edge& other) const { return false; }
};

long long solve(int mask, int n, int k, const vector<Edge>& edges) {
    int cnt1 = 0;
    int tmp = mask;
    while (tmp != 0) {
        cnt1 += (tmp & 1);
        tmp >>= 1;
    }
    if (cnt1 > k) {
        return LONG_LONG_MAX;
    }
    vector<int> xorRes(n);
    DSU dsu(n);
    for (const Edge& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;
        if (((mask >> u) & 1) == 1 || ((mask >> v) & 1) == 1) {
            continue;
        }
        u = dsu.Find(u);
        v = dsu.Find(v);
        if (u != v) {
            xorRes[u] ^= xorRes[v];
            dsu.Unite(u, v);
        }
        xorRes[u] ^= w;
    }
    set<int> st;
    long long ret = 0;
    for (int i = 0; i < n; ++i) {
        int f = dsu.Find(i);
        if (st.find(f) != st.end()) {
            continue;
        }
        st.insert(f);
        ret += xorRes[f];
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        --edges[i].u;
        --edges[i].v;
    }
    long long ans = LONG_LONG_MAX;
    for (int i = 1; i < (1 << n); ++i) {
        ans = min(ans, solve(i, n, k, edges));
    }
    cout << ans << '\n';

    return 0;
}