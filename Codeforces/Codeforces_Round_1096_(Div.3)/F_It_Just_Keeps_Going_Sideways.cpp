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
    long long sum, len;

    Node() {}

    Node(long long sum, long long len) : sum(sum), len(len) {}

    bool operator<(const Node& other) const { return false; }
};

Node op(Node s1, Node s2) { return Node(s1.sum + s2.sum, s1.len + s2.len); }

Node e() { return Node(0, 0); }

Node mapping(long long f, Node s) { return Node(s.sum + f * s.len, s.len); }

long long composition(long long f1, long long f2) { return f1 + f2; }

long long id() { return 0; }

int main() {
    ios::sync_with_stdio(false);

    int T, n;
    vector<long long> num;
    cin >> T;
    while (T--) {
        cin >> n;
        num.assign(n + 1, 0);
        LazySegtree<Node, op, e, long long, mapping, composition, id> tree(
            vector<Node>(n + 1, Node(0, 1)));
        long long tmp = 0;
        FenwickTree<long long> lsum(n + 1), rsum(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
            rsum.Add(num[i], 1);
            if (num[i] != n) {
                tmp += tree.Prod(num[i] + 1, n + 1).sum;
            }
            tree.Apply(1, num[i] + 1, 1);
        }
        long long ans = tmp;
        for (int i = 1; i <= n; ++i) {
            rsum.Add(num[i], -1);
            ans = max(ans, tmp + lsum.Sum(num[i], n + 1) -
                               (n - rsum.Sum(num[i], n + 1) - i));
            lsum.Add(num[i], 1);
        }
        cout << ans << endl;
    }

    return 0;
}
