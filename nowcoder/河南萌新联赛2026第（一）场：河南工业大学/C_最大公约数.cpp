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

int opGcd(int s1, int s2) { return __gcd(s1, s2); }

typedef SparseTable<int, opMin> stMin;
typedef SparseTable<int, opGcd> stGcd;

int findNext(int l, int idx, const stMin& stmin, const stGcd& stgcd, int n) {
    int mn = stmin.Query(l, idx + 1);
    int gcd = stgcd.Query(l, idx + 1);
    int low = idx + 1;
    int high = n + 1;
    while (high - low > 1) {
        int mid = (high + low) >> 1;
        if (stmin.Query(l, mid) == mn && stgcd.Query(l, mid) == gcd) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        stMin stmin(a);
        stGcd stgcd(a);
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int idx = i;
            while (idx < n) {
                int mn = stmin.Query(i, idx + 1);
                int gcd = stgcd.Query(i, idx + 1);
                int nextIdx = findNext(i, idx, stmin, stgcd, n);
                if (mn == gcd) {
                    ans += nextIdx - idx;
                }
                idx = nextIdx;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}