#include <bits/stdc++.h>
using namespace std;

int solve(int l, int r, int k) {
    int ret = 0;
    for (int i = l; i <= r; ++i) {
        for (int j = i + 1; j <= r; ++j) {
            if ((i ^ j) % k == 0) {
                ++ret;
            }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    int l, r, k;
    cin >> l >> r >> k;
    r -= l;
    if (r < k) {
        cout << 0 << '\n';
        return 0;
    }
    long long a1 = 1;
    long long an_1 = r / k - 1;
    long long ans = (a1 + an_1) * an_1 / 2 * k;
    ans += (r % k + 1) * (r / k);
    cout << ans << '\n';

    return 0;
}