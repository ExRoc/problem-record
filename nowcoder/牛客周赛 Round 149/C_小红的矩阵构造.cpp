#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    if (n == 1 && m == 1) {
        cout << "YES" << '\n';
        cout << k << '\n';
        return 0;
    }
    vector<vector<int>> ans(n, vector<int>(m, 1));
    for (int i = 1; i < n * m; ++i) {
        int x = i / m;
        int y = i % m;
        if ((x + y) % 2 == 1) {
            ans[x][y] = 2;
        }
    }
    int sum = n * m / 2 * 3 + 1 * (n * m % 2);
    if (sum > k) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    int x = 1 / m;
    int y = 1 % m;
    ans[x][y] += k - sum;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}