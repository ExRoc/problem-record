#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        int l;
        cin >> l;
        a[i].assign(l + 1, 0);
        for (int j = 1; j <= l; ++j) {
            cin >> a[i][j];
        }
    }
    int x, y;
    cin >> x >> y;
    cout << a[x][y] << '\n';

    return 0;
}