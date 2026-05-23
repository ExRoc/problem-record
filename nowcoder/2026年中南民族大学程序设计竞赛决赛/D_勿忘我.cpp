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

int op(int s1, int s2) { return max(s1, s2); }

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, m, l;
        cin >> n >> m >> l;
        int nn = (n << 1);
        vector<int> sum1(nn + 1, 0), sum2(nn + 1, 0);
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            ++sum1[a];
            --sum1[a + b];
            ++sum2[a];
        }
        vector<int> f(nn + 1);
        for (int i = 1; i <= nn; ++i) {
            sum1[i] += sum1[i - 1];
            sum2[i] += sum2[i - 1];
            f[i] = min(sum1[i] + m, sum2[i]);
        }
        SparseTable<int, op> st(f);
        int ans = n;
        for (int i = 1; i <= n - l + 1; ++i) {
            ans = min(ans, st.Query(i, i + l));
        }
        cout << ans << '\n';
    }

    return 0;
}