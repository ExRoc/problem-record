#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (i == 0 || j == 0) {
                res ^= a[i][j];
            }
        }
    }
    int x;
    cin >> x;
    cout << "YES" << '\n';
    cout << "1 1 " << (res ^ x ^ a[0][0]) << '\n';
    cout << "1 1" << '\n';

    return 0;
}