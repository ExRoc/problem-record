#include <bits/stdc++.h>
using namespace std;

long long sum(long long n, long long x) {
    n /= x;
    if (n % 4 == 3) {
        return 0;
    }
    long long ret = 0;
    for (long long i = n - n % 4; i <= n; ++i) {
        ret ^= i;
    }
    return ret * x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long l, r, x;
    cin >> l >> r >> x;
    long long ll = (l + x - 1) / x * x;
    long long rr = r / x * x;
    if (ll > rr) {
        cout << 0 << '\n';
        return 0;
    }
    cout << (sum(rr, x) ^ sum(ll - 1, x)) << '\n';

    return 0;
}