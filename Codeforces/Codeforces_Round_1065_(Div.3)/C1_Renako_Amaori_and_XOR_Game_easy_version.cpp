#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            res ^= a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            res ^= b[i];
        }
        if (res == 0) {
            cout << "Tie" << '\n';
            continue;
        }
        int idx;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                idx = i;
            }
        }
        if (idx % 2 == 0) {
            cout << "Ajisai" << '\n';
        } else {
            cout << "Mai" << '\n';
        }
    }

    return 0;
}