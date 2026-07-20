#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long ans = 0;
    vector<long long> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ans += max(0LL, a[i] - a[i - 1]);
    }
    cout << ans << '\n';

    return 0;
}