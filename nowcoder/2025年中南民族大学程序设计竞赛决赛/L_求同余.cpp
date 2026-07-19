#include <bits/stdc++.h>
using namespace std;

long long fastPow(long long res, long long n, long long MOD) {
    res %= MOD;
    long long ans;
    for (ans = 1; n != 0; n >>= 1) {
        if ((n & 1) == 1) {
            ans = ans * res % MOD;
        }
        res = res * res % MOD;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long l, r, n;
    cin >> l >> r >> n;
    long long mod = (1LL << (n + 2));
    long long p = (1LL << n);
    long long ans = 0;
    for (long long i = l; i <= r; ++i) {
        if (fastPow(i, p, mod) == 1) {
            ++ans;
        }
    }
    cout << ans << '\n';

    return 0;
}