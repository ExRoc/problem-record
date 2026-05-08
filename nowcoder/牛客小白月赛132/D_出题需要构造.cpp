#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        if (n != m || n == 1) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        cout << 2 << '\n';
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cout << (i + j - 2) % n + 1 << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}