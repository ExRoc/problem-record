#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MOD = 998244353;
const int maxn = 300000 + 100;
int n, m;
LL tmp, ans, idx, lcnt, rcnt;
LL a[maxn], b[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }
    sort(b + 1, b + 1 + m);
    for (int i = 1; i <= n; ++i) {
        tmp += abs(a[i] - b[1]);
        if (a[i] <= b[1]) {
            idx = i;
        }
    }
    ans = tmp;
    LL last = b[1];
    lcnt = idx;
    rcnt = n - idx;
    for (int i = 2; i <= m; ++i) {
        while (idx < n && a[idx + 1] <= b[i]) {
            ++idx;
            tmp += (a[idx] - last) * lcnt;
            tmp -= (a[idx] - last) * rcnt;
            tmp = (tmp % MOD + MOD) % MOD;
            last = a[idx];
            lcnt = idx;
            rcnt = (n - idx);
        }
        tmp += (b[i] - last) * lcnt;
        tmp -= (b[i] - last) * rcnt;
        tmp = (tmp % MOD + MOD) % MOD;
        ans += tmp;
        ans = (ans % MOD + MOD) % MOD;
        last = b[i];
    }
    cout << ans % MOD << endl;

    return 0;
}
