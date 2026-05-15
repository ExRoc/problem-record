#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            if ((a | x) == x) {
                res |= a;
            }
        }
        cout << (res == x ? "YES" : "NO") << '\n';
    }

    return 0;
}