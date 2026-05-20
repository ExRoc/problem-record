#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[0] == 1) {
        cout << 0 << '\n';
        return 0;
    }
    long long g = 0;
    for (int i = 1; i < n; ++i) {
        g = __gcd(g, a[i] - a[0]);
    }
    if (g == 0) {
        cout << 1 << '\n';
        return 0;
    }
    if (g == 1) {
        cout << a[0] - 1 << '\n';
        return 0;
    }
    vector<long long> facs;
    long long tmp = g;
    for (long long i = 2; i <= tmp / i; ++i) {
        if (tmp % i == 0) {
            facs.push_back(i);
            while (tmp % i == 0) {
                tmp /= i;
            }
        }
    }
    if (tmp > 1) {
        facs.push_back(tmp);
    }
    int cnt = facs.size();
    long long ans = 0;
    for (int i = 1; i < (1 << cnt); ++i) {
        long long p = 1;
        long long f = -1;
        for (int j = 0; j < cnt; ++j) {
            if (((i >> j) & 1) == 1) {
                p *= facs[j];
                f *= -1;
            }
        }
        ans += (a[0] - 1) / p * f;
    }
    ans = a[0] - 1 - ans;
    cout << ans << '\n';

    return 0;
}