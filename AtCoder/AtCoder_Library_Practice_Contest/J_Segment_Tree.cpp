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

int op(int a, int b) { return max(a, b); }

int e() { return -1; }

int main() {
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> num(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
    }
    SegTree<int, op, e> tree(num);
    while (q--) {
        int T, a, b;
        cin >> T >> a >> b;
        if (T == 1) {
            tree.Set(a, b);
        } else if (T == 2) {
            cout << tree.Prod(a, b + 1) << endl;
        } else {
            cout << tree.MaxRight(a, [&](int s) { return s < b; }) << endl;
        }
    }

    return 0;
}