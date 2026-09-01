#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        long long ans = 0;
        vector<int> idxA(n + 2, n + 1), idxB(n + 2, n + 1);
        vector<int> r(n + 2, n + 1);
        for (int i = n; i >= 1; --i) {
            idxA[a[i]] = i;
            idxB[b[i]] = i;
            if (a[i] == b[i]) {
                if (idxA[a[i] + 1] == idxB[b[i] + 1]) {
                    r[a[i]] = r[a[i] + 1];
                } else {
                    r[a[i]] = min(idxA[a[i] + 1], idxB[b[i] + 1]);
                }
            }
            if (idxA[1] != idxB[1] || idxA[1] == n + 1) {
                ans += min(idxA[1], idxB[1]) - i;
            } else {
                ans += r[1] - i;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}