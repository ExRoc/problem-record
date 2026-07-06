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

double cal(long long fenzi, long long MOD, long long n) {
    return (fastPow(16, n, MOD) * fenzi % MOD) * 1.0 / MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        int n;
        cin >> n;
        double ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += cal(4, 8 * i + 1, n - i - 1);
            ans -= cal(2, 8 * i + 4, n - i - 1);
            ans -= cal(1, 8 * i + 5, n - i - 1);
            ans -= cal(1, 8 * i + 6, n - i - 1);
            ans -= floor(ans);
        }
        ans += (4.0 / (8 * n + 1) - 2.0 / (8 * n + 4) - 1.0 / (8 * n + 5) -
                1.0 / (8 * n + 6)) /
               16;
        ans *= 16;
        int intAns = floor(ans);
        cout << "Case #" << cas << ": " << n << " ";
        if (intAns < 10) {
            cout << intAns << '\n';
        } else {
            cout << (char)('A' + intAns - 10) << '\n';
        }
    }

    return 0;
}