#include <bits/stdc++.h>
using namespace std;

template <class T>
struct FenwickTree {
   public:
    FenwickTree() : n_(0) {}
    explicit FenwickTree(int n) : n_(n), data_(n) {}

    void Add(int p, T x) {
        assert(0 <= p && p < n_);
        ++p;
        while (p <= n_) {
            data_[p - 1] += x;
            p += p & -p;
        }
    }

    T Sum(int l, int r) {
        assert(0 <= l && l <= r && r <= n_);
        return Sum(r) - Sum(l);
    }

   private:
    int n_;
    vector<T> data_;

    T Sum(int r) {
        T s = 0;
        while (r > 0) {
            s += data_[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

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

struct Node {
    int mn, mnIdx, mx, mxIdx;

    Node() {
        mn = INT_MAX;
        mnIdx = 0;
        mx = INT_MIN;
        mxIdx = 0;
    }

    Node(int mn, int mnIdx, int mx, int mxIdx)
        : mn(mn), mnIdx(mnIdx), mx(mx), mxIdx(mxIdx) {}

    bool operator<(const Node& other) const { return false; }
};

Node op(Node s1, Node s2) {
    Node node;
    if (s1.mn < s2.mn) {
        node.mn = s1.mn;
        node.mnIdx = s1.mnIdx;
    } else if (s1.mn > s2.mn) {
        node.mn = s2.mn;
        node.mnIdx = s2.mnIdx;
    } else {
        node.mn = s1.mn;
        if (s1.mnIdx < s2.mnIdx) {
            node.mnIdx = s1.mnIdx;
        } else {
            node.mnIdx = s2.mnIdx;
        }
    }
    if (s1.mx > s2.mx) {
        node.mx = s1.mx;
        node.mxIdx = s1.mxIdx;
    } else if (s1.mx < s2.mx) {
        node.mx = s2.mx;
        node.mxIdx = s2.mxIdx;
    } else {
        node.mx = s1.mx;
        if (s1.mxIdx < s2.mxIdx) {
            node.mxIdx = s1.mxIdx;
        } else {
            node.mxIdx = s2.mxIdx;
        }
    }
    return node;
}

Node e() { return Node(); }

typedef SegTree<Node, op, e> segTree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> t(n + 1);
    vector<FenwickTree<int>> kthTree;
    kthTree.push_back(FenwickTree<int>(0));
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
        kthTree.push_back(FenwickTree<int>(t[i] + 1));
        for (int j = 1; j <= t[i]; ++j) {
            kthTree[i].Add(j, 1);
        }
    }
    vector<segTree> goods;
    goods.push_back(segTree());
    for (int i = 1; i <= n; ++i) {
        vector<Node> nodes(t[i] + 1);
        nodes[0] = e();
        for (int j = 1; j <= t[i]; ++j) {
            cin >> nodes[j].mn;
            nodes[j].mx = nodes[j].mn;
            nodes[j].mnIdx = nodes[j].mxIdx = j;
        }
        for (int j = 1; j <= t[i]; ++j) {
            int b;
            cin >> b;
            if (b == 0) {
                nodes[j].mn = -nodes[j].mn;
                nodes[j].mx = nodes[j].mn;
            }
        }
        goods.push_back(segTree(nodes));
    }
    while (m--) {
        int id, op, k;
        cin >> id >> op >> k;
        int low = 0;
        int high = t[id];
        while (high - low > 1) {
            int mid = (high + low) >> 1;
            if (kthTree[id].Sum(0, mid + 1) >= k) {
                high = mid;
            } else {
                low = mid;
            }
        }
        Node node = goods[id].Prod(1, high + 1);
        if (op == 0) {
            if (node.mn >= 0) {
                cout << -1 << '\n';
            } else {
                cout << kthTree[id].Sum(0, node.mnIdx + 1) << '\n';
                kthTree[id].Add(node.mnIdx, -1);
                goods[id].Set(node.mnIdx, e());
            }
        } else {
            if (node.mx <= 0) {
                cout << -1 << '\n';
            } else {
                cout << kthTree[id].Sum(0, node.mxIdx + 1) << '\n';
                kthTree[id].Add(node.mxIdx, -1);
                goods[id].Set(node.mxIdx, e());
            }
        }
    }

    return 0;
}