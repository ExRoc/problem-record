#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> d(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int pre = (i - 1 + n) % n;
        if (s[pre] != s[i]) {
            d[i] = 1;
            ++ans;
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        ans -= d[l];
        d[l] = 1 - d[l];
        ans += d[l];
        r = (r + 1) % n;
        ans -= d[r];
        d[r] = 1 - d[r];
        ans += d[r];
        cout << ans << '\n';
    }

    return 0;
}