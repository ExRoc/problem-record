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

int cal(int idx, int n, const vector<vector<int>>& st, int logSize) {
    int ret = n;
    int stepTmp = 0;
    int idxTmp = idx;
    while (idxTmp + 1 < idx + n) {
        int dTmp;
        for (int j = 0; j <= logSize; ++j) {
            if (st[idxTmp][j] >= idx + n) {
                dTmp = j;
                break;
            }
        }
        ret = min(ret, stepTmp + (1 << dTmp));
        stepTmp += (1 << (dTmp - 1));
        if (dTmp == 0) {
            break;
        }
        idxTmp = st[idxTmp][dTmp - 1];
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, m, alpha;
        cin >> n >> m >> alpha;
        vector<int> theta(n * 2);
        const int R = 3.6e7;
        for (int i = 0; i < n; ++i) {
            cin >> theta[i];
            theta[i + n] = theta[i] + R;
        }
        sort(theta.begin(), theta.end());
        int logSize = Log2Table::Get(2 * n) + 1;
        vector<vector<int>> st(2 * n + 1, vector<int>(logSize + 1));
        for (int i = 0; i < 2 * n; ++i) {
            st[i][0] = min({(int)(upper_bound(theta.begin(), theta.end(),
                                              theta[i] + alpha) -
                                  theta.begin()),
                            i + m, 2 * n});
        }
        st[2 * n][0] = 2 * n;
        for (int j = 1; j <= logSize; ++j) {
            for (int i = 0; i <= 2 * n; ++i) {
                st[i][j] = st[st[i][j - 1]][j - 1];
            }
        }
        int ans = n;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, cal(i, n, st, logSize));
        }
        cout << ans << '\n';
    }

    return 0;
}