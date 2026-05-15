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

int op(int a, int b) { return __gcd(a, b); }

int findNext(int l, int idx, int n, SparseTable<int, op>& st) {
    int low = idx;
    int high = n + 1;
    int mid;
    int g = st.Query(l, idx + 1);
    while (high - low > 1) {
        mid = (low + high) >> 1;
        if (st.Query(l, mid + 1) == g) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return high;
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        SparseTable<int, op> st(a);
        vector<long long> ans(n + 1, 0);
        for (int l = 1; l <= n; ++l) {
            int next;
            for (int r = l; r <= n; r = next) {
                next = findNext(l, r, n, st);
                ans[st.Query(l, next)] += next - r;
            }
        }
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}