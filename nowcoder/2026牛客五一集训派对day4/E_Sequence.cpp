#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> sum(n + 1);
        vector<int> cnt(n + 1);
        for (int i = 1; i <= n; ++i) {
            long long x;
            cin >> x;
            sum[i] = sum[i - 1] + (x & 1);
            cnt[i] = cnt[i - 1] + (sum[i] & 1);
        }
        while (q--) {
            int l, r, k;
            cin >> l >> r >> k;
            if ((sum[r] & 1) != (sum[l - 1] & 1)) {
                cout << "NO" << '\n';
                continue;
            }
            int ccnt = (l == 1 ? cnt[r - 1] : cnt[r - 1] - cnt[l - 2]);
            if (sum[r] % 2 == 0) {
                ccnt = r - l + 1 - ccnt;
            }
            if (ccnt >= k) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }

    return 0;
}