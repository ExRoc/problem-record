#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

template <class S, S (*op)(S, S)>
class SparseTable {
   public:
    SparseTable(const vector<S>& arr) : n_(arr.size()), log2_(n_ + 1), st_() {
        log2_[1] = 0;
        for (int i = 2; i <= n_; ++i) {
            log2_[i] = log2_[i / 2] + 1;
        }

        int k = log2_[n_] + 1;
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
        int j = log2_[len];
        return op(st_[j][l], st_[j][r - (1 << j)]);
    }

   private:
    int n_;
    vector<int> log2_;
    vector<vector<S>> st_;
};

int op(int a, int b) { return max(a, b); }

long long findL(int idx, const SparseTable<int, op>& st, int x) {
    int low = 0;
    int high = idx;
    int mid;
    while (high - low > 1) {
        mid = (high + low) >> 1;
        if (st.Query(mid, idx + 1) <= x) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high;
}

long long findR(int idx, const SparseTable<int, op>& st, int x, int n) {
    int low = idx;
    int high = n + 1;
    int mid;
    while (high - low > 1) {
        mid = (high + low) >> 1;
        if (st.Query(idx, mid + 1) <= x) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> num(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
        }
        SparseTable<int, op> st(num);
        for (int i = 1; i <= n; ++i) {
            long long l = findL(i, st, num[i]);
            long long r = findR(i, st, num[i], n);
            cout << (i - l + 1) * (n - i + 1) + (r - i + 1) * (l - 1) << " ";
        }
        cout << '\n';
    }

    return 0;
}