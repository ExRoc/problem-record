#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            int t;
            cin >> t;
            if (t != s[i]) {
                ++cnt;
            }
        }
        while (cnt % 2 == 0 && k % 2 == 0) {
            cnt >>= 1;
            k >>= 1;
        }
        if (k % 2 == 1) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}