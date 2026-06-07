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

int main() {
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;
    long long ans = 0;
    FenwickTree<int> rowPre(Q + 1), colPre(Q + 1);
    vector<int> rowIdx(N + 1, 0), colIdx(N + 1, 0);
    for (int i = 1; i <= Q; ++i) {
        int type, RC;
        cin >> type >> RC;
        if (type == 1) {
            if (rowIdx[RC] != 0) {
                ans += colPre.Sum(rowIdx[RC], i);
                rowPre.Add(i, 1);
                rowPre.Add(rowIdx[RC], -1);
            } else {
                ans += N;
                rowPre.Add(i, 1);
            }
            rowIdx[RC] = i;
        } else {
            if (colIdx[RC] != 0) {
                ans -= rowPre.Sum(colIdx[RC], i);
                colPre.Add(i, 1);
                colPre.Add(colIdx[RC], -1);
            } else {
                ans -= rowPre.Sum(0, i);
                colPre.Add(i, 1);
            }
            colIdx[RC] = i;
        }
        cout << ans << '\n';
    }

    return 0;
}