#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for (int j = 0; j < i; ++j) {
                long long tmp = __builtin_popcount((int)(a[i] ^ a[j]));
                ans += tmp * tmp;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}