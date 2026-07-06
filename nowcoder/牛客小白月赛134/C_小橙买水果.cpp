#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > a[(i - 1 + n) % n]) {
                idx = i;
            }
        }
        long long ans = a[idx];
        int tmp = (idx + 1) % n;
        while (tmp != idx) {
            if (a[tmp] > a[(tmp - 1 + n) % n]) {
                ans += a[tmp];
            }
            tmp = (tmp + 1) % n;
        }
        cout << ans << '\n';
    }

    return 0;
}