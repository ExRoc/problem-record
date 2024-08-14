#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
const LL MOD = 1000000007;
int T, n;
LL k;
LL sum;
LL num[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n >> k;
        LL tmp = 0;
        LL mx = 0;
        sum = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
            sum += num[i];
            tmp += num[i];
            tmp = max(tmp, 0LL);
            mx = max(mx, tmp);
        }
        sum = (sum % MOD + MOD) % MOD;
        mx = (mx % MOD + MOD) % MOD;
        tmp = mx;
        mx = 0;
        for (int i = 0; i < k; ++i) {
            mx = (mx + tmp) % MOD;
            tmp = (tmp * 2) % MOD;
        }
        cout << (sum + mx) % MOD << endl;
    }

    return 0;
}
