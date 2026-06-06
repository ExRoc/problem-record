#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 15;

long long fact[20], inv_fact[20];

long long modpow(long long a, long long e) {
    long long res = 1;
    while (e) {
        if (e & 1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; ++i) fact[i] = fact[i - 1] * i % MOD;
    inv_fact[MAXN] = modpow(fact[MAXN], MOD - 2);
    for (int i = MAXN; i >= 1; --i) inv_fact[i - 1] = inv_fact[i] * i % MOD;
}

// 计算 C(n, k) mod MOD, 其中 0 <= k <= MAXN
long long comb(long long n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0) return 1;
    long long res = 1;
    for (int i = 0; i < k; ++i) {
        res = res * ((n - i) % MOD) % MOD;
    }
    res = res * inv_fact[k] % MOD;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();

    int t;
    cin >> t;
    while (t--) {
        int N;
        long long S;
        cin >> N >> S;
        vector<long long> L(N);
        for (int i = 0; i < N; ++i) cin >> L[i];

        long long ans = 0;
        for (int mask = 0; mask < (1 << N); ++mask) {
            int bits = __builtin_popcount(mask);
            long long sum = 0;
            for (int i = 0; i < N; ++i) {
                if (mask >> i & 1) {
                    sum += L[i] + 1;
                }
            }
            if (sum > S) continue;          // 剩余负数，组合数为 0
            long long n = S - sum + N - 1;  // 组合数上标
            if (n < N - 1) continue;        // 组合数为 0
            long long ways = comb(n, N - 1);
            if (bits & 1)
                ans = (ans - ways + MOD) % MOD;
            else
                ans = (ans + ways) % MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}