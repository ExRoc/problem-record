#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<long long> a(n + 1);
    vector<__int128_t> sum(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    __int128_t half = sum[n] / 2;
    __int128_t ans = 0;
    int r = 1;
    for (int l = 1; l <= n; ++l) {
        while (r <= n && sum[r] - sum[l - 1] <= half) {
            ++r;
        }
        ans = max(ans, (sum[r - 1] - sum[l - 1]) *
                           (sum[n] - (sum[r - 1] - sum[l - 1])));
        if (r <= n) {
            ans = max(ans,
                      (sum[r] - sum[l - 1]) * (sum[n] - (sum[r] - sum[l - 1])));
        }
    }
    cout << (long long)(ans % 998244353) << '\n';

    return 0;
}