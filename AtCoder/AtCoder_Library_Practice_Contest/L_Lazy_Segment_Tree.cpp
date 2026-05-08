#include <bits/stdc++.h>
using namespace std;

template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),
          F (*composition)(F, F), F (*id)()>
class LazySegtree {
   public:
    LazySegtree() : LazySegtree(0) {}
    explicit LazySegtree(int n) : LazySegtree(vector<S>(n, e())) {}
    explicit LazySegtree(const vector<S>& v) : n_(int(v.size())) {
        size_ = BitCeil(static_cast<unsigned int>(n_));
        log_ = CountrZero(static_cast<unsigned int>(size_));
        data_ = vector<S>(2 * size_, e());
        lazy_ = vector<F>(size_, id());
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
        for (int i = log_; i >= 1; --i) {
            Push(p >> i);
        }
        data_[p] = x;
        for (int i = 1; i <= log_; ++i) {
            Update(p >> i);
        }
    }

    S Get(int p) {
        assert(0 <= p && p < n_);
        p += size_;
        for (int i = log_; i >= 1; --i) {
            Push(p >> i);
        }
        return data_[p];
    }

    S Prod(int l, int r) {
        assert(0 <= l && l <= r && r <= n_);
        if (l == r) {
            return e();
        }
        l += size_;
        r += size_;
        for (int i = log_; i >= 1; --i) {
            if (((l >> i) << i) != l) {
                Push(l >> i);
            }
            if (((r >> i) << i) != r) {
                Push((r - 1) >> i);
            }
        }
        S sml = e(), smr = e();
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

    S AllProd() { return data_[1]; }

    void Apply(int p, F f) {
        assert(0 <= p && p < n_);
        p += size_;
        for (int i = log_; i >= 1; --i) {
            Push(p >> i);
        }
        data_[p] = mapping(f, data_[p]);
        for (int i = 1; i <= log_; ++i) {
            Update(p >> i);
        }
    }

    void Apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= n_);
        if (l == r) {
            return;
        }
        l += size_;
        r += size_;
        for (int i = log_; i >= 1; --i) {
            if (((l >> i) << i) != l) {
                Push(l >> i);
            }
            if (((r >> i) << i) != r) {
                Push((r - 1) >> i);
            }
        }
        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) {
                    AllApply(l++, f);
                }
                if (r & 1) {
                    AllApply(--r, f);
                }
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }
        for (int i = 1; i <= log_; ++i) {
            if (((l >> i) << i) != l) {
                Update(l >> i);
            }
            if (((r >> i) << i) != r) {
                Update((r - 1) >> i);
            }
        }
    }

    template <class G>
    int MaxRight(int l, G g) {
        assert(0 <= l && l <= n_);
        assert(g(e()));
        if (l == n_) {
            return n_;
        }
        l += size_;
        for (int i = log_; i >= 1; --i) {
            Push(l >> i);
        }
        S sm = e();
        do {
            while (l % 2 == 0) {
                l >>= 1;
            }
            if (!g(op(sm, data_[l]))) {
                while (l < size_) {
                    Push(l);
                    l = 2 * l;
                    if (g(op(sm, data_[l]))) {
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

    template <bool (*g)(S)>
    int MaxRight(int l) {
        return MaxRight(l, [](S x) { return g(x); });
    }

    template <class G>
    int MinLeft(int r, G g) {
        assert(0 <= r && r <= n_);
        assert(g(e()));
        if (r == 0) {
            return 0;
        }
        r += size_;
        for (int i = log_; i >= 1; --i) {
            Push((r - 1) >> i);
        }
        S sm = e();
        do {
            --r;
            while (r > 1 && (r % 2)) {
                r >>= 1;
            }
            if (!g(op(data_[r], sm))) {
                while (r < size_) {
                    Push(r);
                    r = 2 * r + 1;
                    if (g(op(data_[r], sm))) {
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

    template <bool (*g)(S)>
    int MinLeft(int r) {
        return MinLeft(r, [](S x) { return g(x); });
    }

   private:
    int n_, size_, log_;
    vector<S> data_;
    vector<F> lazy_;

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

    void AllApply(int k, F f) {
        data_[k] = mapping(f, data_[k]);
        if (k < size_) {
            lazy_[k] = composition(f, lazy_[k]);
        }
    }

    void Push(int k) {
        AllApply(2 * k, lazy_[k]);
        AllApply(2 * k + 1, lazy_[k]);
        lazy_[k] = id();
    }
};

struct Node {
    long long cnt0;
    long long cnt1;
    long long cntInv;

    Node() {}

    Node(long long cnt0, long long cnt1, long long cntInv)
        : cnt0(cnt0), cnt1(cnt1), cntInv(cntInv) {}

    bool operator<(const Node& other) const { return false; }
};

Node op(Node s1, Node s2) {
    return Node(s1.cnt0 + s2.cnt0, s1.cnt1 + s2.cnt1,
                s1.cntInv + s2.cntInv + s1.cnt1 * s2.cnt0);
}

Node e() { return Node(0, 0, 0); }

Node mapping(bool f, Node s) {
    if (f) {
        swap(s.cnt0, s.cnt1);
        s.cntInv = s.cnt0 * s.cnt1 - s.cntInv;
    }
    return s;
}

bool composition(bool f1, bool f2) { return f1 ^ f2; }

bool id() { return false; }

int main() {
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<Node> a(n + 1, Node(0, 0, 0));
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (x == 0) {
            ++a[i].cnt0;
        } else {
            ++a[i].cnt1;
        }
    }
    LazySegtree<Node, op, e, bool, mapping, composition, id> tree(a);
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            tree.Apply(l, r + 1, true);
        } else {
            cout << tree.Prod(l, r + 1).cntInv << '\n';
        }
    }

    return 0;
}