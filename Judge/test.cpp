#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            ans ^= a;
        }
        if (ans == 0) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }

    return 0;
}