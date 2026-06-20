#include <bits/stdc++.h>
using namespace std;

template <class S, S (*op)(S, S), S (*e)()>
class SegTree {
   public:
    SegTree() : SegTree(0) {}
    explicit SegTree(int n) : SegTree(vector<S>(n, e())) {}
    explicit SegTree(const vector<S>& v) : n_(int(v.size())) {
        size_ = BitCeil(static_cast<unsigned int>(n_));
        log_ = CountrZero(static_cast<unsigned int>(size_));
        data_ = vector<S>(2 * size_, e());
        for (int i = 0; i < n_; ++i) {
            data_[size_ + i] = v[i];
        }
        for (int i = size_ - 1; i >= 1; --i) {
            Update(i);
        }
    }

    void Set(int p, S x) {
        assert(0 <= p && p < n_);
        p += size_;
        data_[p] = x;
        for (int i = 1; i <= log_; ++i) {
            Update(p >> i);
        }
    }

    S Get(int p) const {
        assert(0 <= p && p < n_);
        return data_[p + size_];
    }

    S Prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= n_);
        S sml = e(), smr = e();
        l += size_;
        r += size_;
        while (l < r) {
            if (l & 1) {
                sml = op(sml, data_[l++]);
            }
            if (r & 1) {
                smr = op(data_[--r], smr);
            }
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S AllProd() const { return data_[1]; }

    template <class F>
    int MaxRight(int l, F f) const {
        assert(0 <= l && l <= n_);
        assert(f(e()));
        if (l == n_) {
            return n_;
        }
        l += size_;
        S sm = e();
        do {
            while (l % 2 == 0) {
                l >>= 1;
            }
            if (!f(op(sm, data_[l]))) {
                while (l < size_) {
                    l = 2 * l;
                    if (f(op(sm, data_[l]))) {
                        sm = op(sm, data_[l]);
                        ++l;
                    }
                }
                return l - size_;
            }
            sm = op(sm, data_[l]);
            ++l;
        } while ((l & -l) != l);
        return n_;
    }

    template <class F>
    int MinLeft(int r, F f) const {
        assert(0 <= r && r <= n_);
        assert(f(e()));
        if (r == 0) {
            return 0;
        }
        r += size_;
        S sm = e();
        do {
            --r;
            while (r > 1 && (r % 2)) {
                r >>= 1;
            }
            if (!f(op(data_[r], sm))) {
                while (r < size_) {
                    r = 2 * r + 1;
                    if (f(op(data_[r], sm))) {
                        sm = op(data_[r], sm);
                        --r;
                    }
                }
                return r + 1 - size_;
            }
            sm = op(data_[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

   private:
    int n_, size_, log_;
    vector<S> data_;

    static unsigned int BitCeil(unsigned int n) {
        unsigned int x = 1;
        while (x < n) {
            x <<= 1;
        }
        return x;
    }

    static int CountrZero(unsigned int n) {
        if (n == 0) {
            return 32;
        }
        return __builtin_ctz(n);
    }

    void Update(int k) { data_[k] = op(data_[2 * k], data_[2 * k + 1]); }
};

class LCA {
   public:
    LCA() {}

    LCA(const vector<vector<int>>& graph) : graph_(graph) {
        n_ = graph_.size() - 1;
        max_log_ = 1;
        while ((1 << max_log_) <= n_) {
            ++max_log_;
        }
        depth_.assign(n_ + 1, 0);
        up_.assign(n_ + 1, vector<int>(max_log_, 0));
        Dfs(1, 0);
    }

    int Query(int u, int v) {
        if (depth_[u] < depth_[v]) {
            swap(u, v);
        }
        int diff = depth_[u] - depth_[v];
        for (int k = 0; k < max_log_; ++k) {
            if (diff & (1 << k)) {
                u = up_[u][k];
            }
        }
        if (u == v) {
            return u;
        }
        for (int k = max_log_ - 1; k >= 0; --k) {
            if (up_[u][k] != up_[v][k]) {
                u = up_[u][k];
                v = up_[v][k];
            }
        }
        return up_[u][0];
    }

    int Distance(int u, int v) {
        if (u == 0 || v == 0) {
            return 0;
        }
        int lca = Query(u, v);
        return depth_[u] + depth_[v] - 2 * depth_[lca];
    }

   private:
    void Dfs(int u, int p) {
        depth_[u] = depth_[p] + 1;
        up_[u][0] = p;
        for (int k = 1; k < max_log_; ++k) {
            up_[u][k] = up_[up_[u][k - 1]][k - 1];
        }
        for (int v : graph_[u]) {
            if (v == p) {
                continue;
            }
            Dfs(v, u);
        }
    }

    int n_;
    int max_log_;
    vector<vector<int>> graph_;
    vector<vector<int>> up_;
    vector<int> depth_;
};

struct Node {
    int u, v, d;

    Node() { u = v = d = 0; }

    Node(int u, int v, int d) : u(u), v(v), d(d) {}

    bool operator<(const Node& other) const { return d > other.d; }

    friend ostream& operator<<(ostream& out, const Node& node) {
        out << "u = " << node.u << " v = " << node.v << " d = " << node.d;
        return out;
    }
};

Node e() { return Node(0, 0, 0); }

LCA lca;

Node op(Node s1, Node s2) {
    if (s1.u == 0 && s1.v == 0) {
        return s2;
    }
    if (s2.u == 0 && s2.v == 0) {
        return s1;
    }
    vector<Node> nodes;
    if (s1.u != 0 && s2.u != 0) {
        nodes.push_back(Node(s1.u, s2.u, lca.Distance(s1.u, s2.u)));
    }
    if (s1.u != 0 && s2.v != 0) {
        nodes.push_back(Node(s1.u, s2.v, lca.Distance(s1.u, s2.v)));
    }
    if (s1.v != 0 && s2.u != 0) {
        nodes.push_back(Node(s1.v, s2.u, lca.Distance(s1.v, s2.u)));
    }
    if (s1.v != 0 && s2.v != 0) {
        nodes.push_back(Node(s1.v, s2.v, lca.Distance(s1.v, s2.v)));
    }
    if (s1.u != 0 && s1.v != 0) {
        nodes.push_back(s1);
    }
    if (s2.u != 0 && s2.v != 0) {
        nodes.push_back(s2);
    }
    sort(nodes.begin(), nodes.end());
    return nodes[0];
}

int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<vector<int>> G(N + 1);
    for (int i = 1; i < N; ++i) {
        int U, V;
        cin >> U >> V;
        G[U].push_back(V);
        G[V].push_back(U);
    }
    lca = LCA(G);
    vector<Node> nodes(N + 1);
    for (int i = 1; i <= N; ++i) {
        nodes[i].u = i;
    }
    SegTree<Node, op, e> segTree(nodes);
    int Q;
    cin >> Q;
    vector<int> xs(N + 1);
    for (int i = 1; i <= N; ++i) {
        xs[i] = i;
    }
    while (Q--) {
        int x;
        cin >> x;
        if (xs[x] == x) {
            xs[x] = 0;
        } else {
            xs[x] = x;
        }
        segTree.Set(x, Node(xs[x], 0, 0));
        cout << segTree.AllProd().d << '\n';
    }

    return 0;
}