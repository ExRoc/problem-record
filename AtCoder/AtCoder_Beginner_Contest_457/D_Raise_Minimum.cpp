#include <bits/stdc++.h>
using namespace std;

bool judge(__int128_t mn, vector<__int128_t>& a, __int128_t k, int n) {
    __int128_t cnt = 0;
    __int128_t zero = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += max((mn - a[i] + i - 1) / i, zero);
    }
    return cnt <= k;
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    long long k;
    cin >> n >> k;
    vector<__int128_t> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        long long x;
        cin >> x;
        a[i] = x;
    }
    __int128_t low = 1;
    __int128_t high = 3e23;
    ++high;
    __int128_t mid;
    while (high - low > 1) {
        mid = (high + low) >> 1;
        if (judge(mid, a, k, n)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    long long ans = low;
    cout << ans << '\n';

    return 0;
}