#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    if (n == 1 || m == 1) {
        cout << "Yes" << '\n';
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (k > 0) {
                    --k;
                    cout << 1;
                } else {
                    cout << 0;
                }
            }
            cout << '\n';
        }
        return 0;
    }
    int x = 1;
    if (k > n * m / 2) {
        x = 0;
        k = n * m - k;
    }
    if (k < (n / 2) * (m / 2) || k == 0) {
        cout << "No" << '\n';
        return 0;
    }
    vector<vector<int>> ans(n, vector<int>(m, x ^ 1));
    for (int i = 1; i < n; i += 2) {
        for (int j = 1; j < m; j += 2) {
            ans[i][j] = x;
            --k;
        }
    }
    if ((n + 1) / 2 * m >= (m + 1) / 2 * n) {
        for (int i = 0; i < n; i += 2) {
            for (int j = 0; j < m; ++j) {
                if (k > 0) {
                    --k;
                    ans[i][j] = x;
                }
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; j += 2) {
                if (k > 0) {
                    --k;
                    ans[i][j] = x;
                }
            }
        }
    }
    cout << "Yes" << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ans[i][j];
        }
        cout << '\n';
    }

    return 0;
}