#include <bits/stdc++.h>
using namespace std;

void solve12(int n, int q, vector<int>& a, const vector<int>& b) {
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        --l;
        --r;
        if (op == 1) {
            for (int i = l; i <= r; ++i) {
                a[i] += b[i];
            }
        } else {
            int ans = 0;
            for (int i = l; i <= r; ++i) {
                ans = __gcd(ans, a[i]);
            }
            cout << ans << '\n';
        }
    }
}

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

int getRand(int l, int r) {
    int rnd = (rand() << 15) ^ rand();
    rnd &= INT_MAX;
    return rnd % (r - l) + l;
}

void solve(int n, int q, const vector<int>& a, const vector<int>& b) {
    srand(time(NULL));
    FenwickTree<int> sum(n);
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        --l;
        if (op == 1) {
            sum.Add(l, 1);
            if (r < n) {
                sum.Add(r, -1);
            }
        } else {
            int ans = 0;
            if (r - l <= 50) {
                for (int i = l; i < r; ++i) {
                    ans = __gcd(ans, a[i] + b[i] * sum.Sum(0, i + 1));
                }
            } else {
                for (int i = 0; i < 10; ++i) {
                    int idx = getRand(l, r);
                    ans = __gcd(ans, a[idx] + b[idx] * sum.Sum(0, idx + 1));
                }
            }
            cout << ans << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        if (q <= 3000) {
            solve12(n, q, a, b);
            continue;
        }
        solve(n, q, a, b);
    }

    return 0;
}