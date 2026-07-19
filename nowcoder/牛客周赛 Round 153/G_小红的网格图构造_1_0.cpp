#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans[i][j] = (i + j + 1) % 2;
            k -= ans[i][j];
        }
    }
    if (k > 0) {
        cout << "No" << '\n';
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((i + j + 1) % 2 == 0) {
                continue;
            }
            if (i % 2 == 1 && j % 2 == 1) {
                continue;
            }
            if (k < 0) {
                ++k;
                ans[i][j] = 0;
            }
        }
    }
    for (int j = 2; j < m - 1; j += 2) {
        if (k < 0) {
            ++k;
            ans[1][j] = 1;
        }
    }
    for (int i = 2; i < n - 1; i += 2) {
        for (int j = 1; j < m; j += 2) {
            if (k < 0) {
                ++k;
                ans[i][j] = 1;
            }
        }
    }
    if (k < 0) {
        cout << "No" << '\n';
        return 0;
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