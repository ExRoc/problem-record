#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> lSum(n + 1, 0), rSum(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        lSum[i] = __gcd(lSum[i - 1], a[i]);
        rSum[n - i + 1] = __gcd(rSum[n - i + 2], a[n - i + 1]);
    }
    int ans = lSum[n];
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 29; ++j) {
            ans = max(ans,
                      __gcd(__gcd(lSum[i - 1], rSum[i + 1]), a[i] ^ (1 << j)));
        }
    }
    cout << ans << '\n';

    return 0;
}