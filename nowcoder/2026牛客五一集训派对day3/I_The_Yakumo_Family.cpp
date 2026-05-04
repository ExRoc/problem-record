#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<long long> num(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
    }
    const int Log = 31;
    const long long MOD = 998244353;
    vector<vector<long long>> dp1Bit(Log, vector<long long>(n + 1, 0));
    vector<long long> dp1Sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < Log; ++j) {
            dp1Bit[j][i] = dp1Bit[j][i - 1];
            long long bit = ((num[i] >> j) & 1);
            if (bit == 1) {
                dp1Bit[j][i] = ((i - dp1Bit[j][i]) % MOD + MOD) % MOD;
            }
            dp1Sum[i] = ((1 << j) % MOD * dp1Bit[j][i] % MOD + dp1Sum[i]) % MOD;
        }
        dp1Sum[i] = (dp1Sum[i - 1] + dp1Sum[i]) % MOD;
    }
    vector<vector<long long>> dp2Bit(Log, vector<long long>(n + 1, 0));
    vector<long long> dp2Sum(n + 1, 0);
    long long sum = 0;
    for (int i = 2; i <= n; ++i) {
        sum = (sum + dp1Sum[i - 1]) % MOD;
        for (int j = 0; j < Log; ++j) {
            dp2Bit[j][i] = dp2Bit[j][i - 1];
            long long bit = ((num[i] >> j) & 1);
            if (bit == 1) {
                dp2Bit[j][i] = ((sum - dp2Bit[j][i]) % MOD + MOD) % MOD;
            }
            dp2Sum[i] = ((1 << j) % MOD * dp2Bit[j][i] % MOD + dp2Sum[i]) % MOD;
        }
        dp2Sum[i] = (dp2Sum[i] + dp2Sum[i - 1]) % MOD;
    }
    sum = 0;
    vector<vector<long long>> dp3Bit(Log, vector<long long>(n + 1, 0));
    vector<long long> dp3Sum(n + 1, 0);
    for (int i = 3; i <= n; ++i) {
        sum = (sum + dp2Sum[i - 1]) % MOD;
        for (int j = 0; j < Log; ++j) {
            dp3Bit[j][i] = dp3Bit[j][i - 1];
            long long bit = ((num[i] >> j) & 1);
            if (bit == 1) {
                dp3Bit[j][i] = ((sum - dp3Bit[j][i]) % MOD + MOD) % MOD;
            }
            dp3Sum[i] = ((1 << j) % MOD * dp3Bit[j][i] % MOD + dp3Sum[i]) % MOD;
        }
        dp3Sum[i] = (dp3Sum[i] + dp3Sum[i - 1]) % MOD;
    }
    cout << dp3Sum[n] << '\n';

    return 0;
}