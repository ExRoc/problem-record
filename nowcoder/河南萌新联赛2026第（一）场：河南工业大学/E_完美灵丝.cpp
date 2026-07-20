#include <bits/stdc++.h>
using namespace std;

class Log2Table {
   public:
    static int Get(int n) {
        static vector<int> table = {0, 0};
        if (n >= static_cast<int>(table.size())) {
            int old = table.size();
            table.resize(n + 1);
            for (int i = max(2, old); i <= n; ++i) {
                table[i] = table[i / 2] + 1;
            }
        }
        return table[n];
    }
};

template <typename S, S (*op)(S, S)>
class SparseTable {
   public:
    explicit SparseTable(const vector<S>& arr) : n_(arr.size()), st_() {
        int k = Log2Table::Get(n_) + 1;
        st_.assign(k, vector<S>(n_));
        for (int i = 0; i < n_; ++i) {
            st_[0][i] = arr[i];
        }
        for (int j = 1; j < k; ++j) {
            int step = 1 << (j - 1);
            for (int i = 0; i + (1 << j) <= n_; ++i) {
                st_[j][i] = op(st_[j - 1][i], st_[j - 1][i + step]);
            }
        }
    }

    S Query(int l, int r) const {
        int len = r - l;
        int j = Log2Table::Get(len);
        return op(st_[j][l], st_[j][r - (1 << j)]);
    }

   private:
    int n_;
    vector<vector<S>> st_;
};

int opMin(int s1, int s2) { return min(s1, s2); }

int opMax(int s1, int s2) { return max(s1, s2); }

typedef SparseTable<int, opMin> stMin;
typedef SparseTable<int, opMax> stMax;

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

int findMmDLeft(int r, const stMin& stmin, const stMax& stmax, int D, int n) {
    int low = -1;
    int high = r;
    while (high - low > 1) {
        int mid = (high + low) >> 1;
        if (stmax.Query(mid, r + 1) - stmin.Query(mid, r + 1) <= D) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high;
}

int findKLeft(int r, int n, FenwickTree<int>& sum, int K) {
    int high = r;
    int low = -1;
    while (high - low > 1) {
        int mid = (high + low) >> 1;
        if (sum.Sum(mid, r + 1) <= K) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high;
}

int findKRight(int r, int n, FenwickTree<int>& sum, int K) {
    int high = r + 1;
    int low = -1;
    while (high - low > 1) {
        int mid = (high + low) >> 1;
        if (sum.Sum(mid, r + 1) < K) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, K, D;
        cin >> n >> K >> D;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        stMin stmin(a);
        stMax stmax(a);
        FenwickTree<int> sum(n);
        map<int, int> idx;
        long long ans = 0;
        for (int r = 0; r < n; ++r) {
            int Dl = findMmDLeft(r, stmin, stmax, D, n);
            sum.Add(r, 1);
            if (idx.find(a[r]) != idx.end()) {
                sum.Add(idx[a[r]], -1);
            }
            idx[a[r]] = r;
            if (sum.Sum(Dl, r + 1) < K) {
                continue;
            }
            int Kl = max(findKLeft(r, n, sum, K), Dl);
            int Kr = findKRight(r, n, sum, K);
            ans += Kr - Kl;
        }
        cout << ans << '\n';
    }

    return 0;
}