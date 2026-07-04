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

struct Node {
    int zeroCnt, oneCnt, fourCnt, sevenCnt;

    Node() {}

    Node(int zeroCnt, int oneCnt, int fourCnt, int sevenCnt)
        : zeroCnt(zeroCnt),
          oneCnt(oneCnt),
          fourCnt(fourCnt),
          sevenCnt(sevenCnt) {}

    Node(int x) {
        zeroCnt = oneCnt = fourCnt = sevenCnt = 0;
        x = x * x % 9;
        if (x == 0) {
            ++zeroCnt;
        } else if (x == 1) {
            ++oneCnt;
        } else if (x == 4) {
            ++fourCnt;
        } else if (x == 7) {
            ++sevenCnt;
        }
    }

    bool triple() {
        if (zeroCnt % 3 != 0) {
            return false;
        }
        int oneOneSeven = 4 * oneCnt - 2 * fourCnt + sevenCnt;
        if (oneOneSeven % 9 != 0 || oneOneSeven < 0) {
            return false;
        }
        int oneFourFour = (oneCnt + 4 * fourCnt - 2 * sevenCnt);
        if (oneFourFour % 9 != 0 || oneFourFour < 0) {
            return false;
        }
        int fourSevenSeven = -2 * oneCnt + fourCnt + 4 * sevenCnt;
        if (fourSevenSeven % 9 != 0 || fourSevenSeven < 0) {
            return false;
        }
        return true;
    }

    bool operator<(const Node& other) const { return false; }
};

Node op(Node s1, Node s2) {
    return Node(s1.zeroCnt + s2.zeroCnt, s1.oneCnt + s2.oneCnt,
                s1.fourCnt + s2.fourCnt, s1.sevenCnt + s2.sevenCnt);
}

Node e() { return Node(0, 0, 0, 0); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<Node> segTmp;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            segTmp.push_back(Node(a));
        }
        SegTree<Node, op, e> segTree(segTmp);
        while (q--) {
            int op;
            cin >> op;
            if (op == 1) {
                int i, x;
                cin >> i >> x;
                --i;
                segTree.Set(i, Node(x));
            } else {
                int l, r;
                cin >> l >> r;
                --l;
                Node node = segTree.Prod(l, r);
                if (node.triple()) {
                    cout << "Yes" << '\n';
                } else {
                    cout << "No" << '\n';
                }
            }
        }
    }

    return 0;
}