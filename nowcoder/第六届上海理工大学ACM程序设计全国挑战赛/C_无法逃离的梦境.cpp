#include <bits/stdc++.h>
using namespace std;

long long matrixs[100001][30][5][5];
long long ans[5][5], ansTmp[5][5];

void multiply(int c, long long m1[5][5], long long m2[5][5],
              long long m3[5][5]) {
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < c; ++j) {
            m3[i][j] = 2e18;
            for (int k = 0; k < c; ++k) {
                m3[i][j] = min(m3[i][j], m1[i][k] + m2[k][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Log = 29;
    int n, c, q;
    cin >> n >> c >> q;
    vector<vector<int>> p(n + 1, vector<int>(Log + 1));
    for (int i = 1; i <= n; ++i) {
        cin >> p[i][0];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < c; ++j) {
            for (int k = 0; k < c; ++k) {
                cin >> matrixs[i][0][j][k];
            }
        }
    }
    for (int j = 1; j <= Log; ++j) {
        for (int i = 1; i <= n; ++i) {
            p[i][j] = p[p[i][j - 1]][j - 1];
            multiply(c, matrixs[i][j - 1], matrixs[p[i][j - 1]][j - 1],
                     matrixs[i][j]);
        }
    }
    while (q--) {
        int x, k, s, t;
        cin >> x >> k >> s >> t;
        bool flag = false;
        for (int j = Log; j >= 0; --j) {
            if (k < (1 << j)) {
                continue;
            }
            k -= (1 << j);
            if (!flag) {
                flag = true;
                memcpy(ans, matrixs[x][j], sizeof(ans));
            } else {
                multiply(c, ans, matrixs[x][j], ansTmp);
                memcpy(ans, ansTmp, sizeof(ans));
            }
            x = p[x][j];
        }
        cout << ans[s][t] << '\n';
    }

    return 0;
}