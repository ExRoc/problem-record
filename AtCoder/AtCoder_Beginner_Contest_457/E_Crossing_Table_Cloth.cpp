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

int op(int s1, int s2) { return min(s1, s2); }

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> lToR(n + 1), rToL(n + 1);
    vector<int> lmn(n + 1, INT_MAX);
    for (int i = 1; i <= m; ++i) {
        int l, r;
        cin >> l >> r;
        lToR[l].push_back(r);
        rToL[r].push_back(l);
        lmn[l] = min(lmn[l], r);
    }
    for (int i = 1; i <= n; ++i) {
        sort(lToR[i].begin(), lToR[i].end());
        sort(rToL[i].begin(), rToL[i].end());
    }
    SparseTable<int, op> st(lmn);
    int q;
    cin >> q;
    while (q--) {
        int s, t;
        cin >> s >> t;
        pair<int, int> l, r;
        int idxl, idxr;
        if (!lToR[s].empty()) {
            idxl = upper_bound(lToR[s].begin(), lToR[s].end(), t) -
                   lToR[s].begin() - 1;
            if (idxl >= 0) {
                l = make_pair(s, lToR[s][idxl]);
            }
        }
        if (!rToL[t].empty()) {
            idxr = lower_bound(rToL[t].begin(), rToL[t].end(), s) -
                   rToL[t].begin();
            if (idxr < (int)rToL[t].size()) {
                r = make_pair(rToL[t][idxr], t);
            }
        }
        if (l.first != 0 && r.first != 0) {
            if (l.second == t) {
                --idxl;
                if (idxl >= 0) {
                    cout << "Yes" << '\n';
                } else {
                    if (s == t) {
                        cout << "No" << '\n';
                    } else if (st.Query(s + 1, t + 1) <= t) {
                        cout << "Yes" << '\n';
                    } else {
                        cout << "No" << '\n';
                    }
                }
            } else {
                if (l.second >= r.first - 1) {
                    cout << "Yes" << '\n';
                } else {
                    cout << "No" << '\n';
                }
            }
            continue;
        }
        cout << "No" << '\n';
    }

    return 0;
}
