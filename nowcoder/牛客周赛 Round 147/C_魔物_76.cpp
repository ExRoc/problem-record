
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> d(n + 1, 0);
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        d[i] = ((a[i] - a[i - 1]) % 5 + 5) % 5;
        ans += d[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l != 1) {
            ans -= d[l];
            ++d[l];
            d[l] %= 5;
            ans += d[l];
        }
        if (r != n) {
            ans -= d[r + 1];
            --d[r + 1];
            d[r + 1] += 5;
            d[r + 1] %= 5;
            ans += d[r + 1];
        }
        cout << ans << '\n';
    }

    return 0;
}