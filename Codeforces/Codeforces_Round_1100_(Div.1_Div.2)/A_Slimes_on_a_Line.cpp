#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int mn = 1000;
        int mx = 1;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            mn = min(mn, a);
            mx = max(mx, a);
        }
        cout << (mx - mn + 1) / 2 << '\n';
    }

    return 0;
}