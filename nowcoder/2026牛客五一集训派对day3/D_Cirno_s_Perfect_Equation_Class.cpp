#include <bits/stdc++.h>
using namespace std;

int judge(long long k, long long c, long long n, long long b) {
    long long a = (c - b) / k;
    if (a <= 0 || b <= 0) {
        return 0;
    }
    if (__gcd(a, b) < n) {
        return 0;
    }
    if (k * a + b != c) {
        return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) {
        long long k, c, n;
        cin >> k >> c >> n;
        int ans = 0;
        for (long long i = 1; i <= c / i; ++i) {
            if (c % i != 0) {
                continue;
            }
            ans += judge(k, c, n, i) + judge(k, c, n, c / i);
        }
        cout << ans << '\n';
    }

    return 0;
}