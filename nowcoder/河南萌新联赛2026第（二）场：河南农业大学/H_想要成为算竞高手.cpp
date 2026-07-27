#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x, y;
    cin >> n >> x >> y;
    if (x == 0 || y == 0) {
        cout << "NO" << '\n';
        return 0;
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        ans += max((a + x - 1) / x, (a + y - 1) / y);
    }
    cout << "YES" << '\n' << ans << '\n';

    return 0;
}