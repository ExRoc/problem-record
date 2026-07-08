#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1);
        long long sum = 0;
        long long ans = LONG_LONG_MAX;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
            ans = min(ans, sum / i);
            cout << ans << ' ';
        }
        cout << '\n';
    }

    return 0;
}