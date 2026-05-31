#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    long long k;
    cin >> n >> k;
    long long ans = abs(k);
    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        ans = min(ans, abs(x) + abs(k - y));
    }
    cout << ans << '\n';

    return 0;
}