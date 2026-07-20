#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n + 1);
    vector<long long> d(n + 1);
    bool allDEqual = true;
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
        if (i > 1 && d[i] != d[2]) {
            allDEqual = false;
        }
        if (i > 2) {
            ans = __gcd(ans, d[i] - d[i - 1]);
        }
    }
    if (allDEqual) {
        cout << -1 << '\n';
        return 0;
    }
    cout << abs(ans) << '\n';

    return 0;
}