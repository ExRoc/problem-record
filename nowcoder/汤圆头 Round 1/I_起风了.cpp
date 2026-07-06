#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        long long low = 1;
        long long high = m + 1;
        while (high - low > 1) {
            long long mid = (high + low) >> 1;
            if (1 + mid <= m * 2 / mid) {
                low = mid;
            } else {
                high = mid;
            }
        }
        long long ans1 = m % n;
        if (ans1 == 0) {
            ans1 = n;
        }
        long long ans2 = m - (1 + low) * low / 2;
        if (ans2 == 0) {
            ans2 = low;
        }
        cout << ans1 << " " << ans2 << '\n';
    }

    return 0;
}