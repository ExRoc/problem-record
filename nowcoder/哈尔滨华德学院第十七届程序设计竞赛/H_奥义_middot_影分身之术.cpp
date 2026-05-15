#include <bits/stdc++.h>
using namespace std;

__int128_t dfs(__int128_t k, __int128_t n, __int128_t m) {
    if (n == 1 || m == 1) {
        return 0;
    }
    __int128_t ret = dfs(k, n - 1, (m + 1) / 2);
    if (m % 2 == 0) {
        ret = (ret + 1) % (k + 1);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    unsigned long long k, n, m;
    cin >> k >> n >> m;
    unsigned long long ans = dfs(k, n, m);
    cout << ans << '\n';

    return 0;
}