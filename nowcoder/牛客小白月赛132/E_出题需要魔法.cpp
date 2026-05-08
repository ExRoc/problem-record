#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SparseTable {
   public:
    SparseTable(const vector<T>& arr)
        : n_(arr.size()), log2_(n_ + 1), st_min_(), st_max_() {
        log2_[1] = 0;
        for (int i = 2; i <= n_; ++i) {
            log2_[i] = log2_[i / 2] + 1;
        }

        int k = log2_[n_] + 1;
        st_min_.assign(k, vector<T>(n_));
        st_max_.assign(k, vector<T>(n_));

        for (int i = 0; i < n_; ++i) {
            st_min_[0][i] = arr[i];
            st_max_[0][i] = arr[i];
        }

        for (int j = 1; j < k; ++j) {
            int step = 1 << (j - 1);
            for (int i = 0; i + (1 << j) <= n_; ++i) {
                st_min_[j][i] =
                    min(st_min_[j - 1][i], st_min_[j - 1][i + step]);
                st_max_[j][i] =
                    max(st_max_[j - 1][i], st_max_[j - 1][i + step]);
            }
        }
    }

    T QueryMin(int l, int r) const {
        int j = log2_[r - l + 1];
        return min(st_min_[j][l], st_min_[j][r - (1 << j) + 1]);
    }

    T QueryMax(int l, int r) const {
        int j = log2_[r - l + 1];
        return max(st_max_[j][l], st_max_[j][r - (1 << j) + 1]);
    }

   private:
    int n_;
    vector<int> log2_;
    vector<vector<T>> st_min_;
    vector<vector<T>> st_max_;
};

long long findL(int idx, const SparseTable<int>& st, int x) {
    int low = 0;
    int high = idx;
    int mid;
    while (high - low > 1) {
        mid = (high + low) >> 1;
        if (st.QueryMax(mid, idx) <= x) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high;
}

long long findR(int idx, const SparseTable<int>& st, int x, int n) {
    int low = idx;
    int high = n + 1;
    int mid;
    while (high - low > 1) {
        mid = (high + low) >> 1;
        if (st.QueryMax(idx, mid) <= x) {
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
        SparseTable<int> st(num);
        for (int i = 1; i <= n; ++i) {
            long long l = findL(i, st, num[i]);
            long long r = findR(i, st, num[i], n);
            cout << (i - l + 1) * (n - i + 1) + (r - i + 1) * (l - 1) << " ";
        }
        cout << '\n';
    }

    return 0;
}