#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long LL;
const int maxn = 5000 + 100;
int n, m;
LL X;
LL A[maxn], B[maxn], Lmin[maxn], dp[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m >> X;
    for (int i = 1; i <= m; ++i) {
        cin >> A[i] >> B[i];
    }
    memset(Lmin, 0x3f, sizeof(Lmin));
    for (LL i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            Lmin[i] = min(Lmin[i], i * A[j] + i * (i - 1) / 2 * B[j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] = Lmin[i];
        for (int j = 1; j < i; ++j) {
            dp[i] = min(dp[i], dp[i - j] + X + Lmin[j]);
        }
    }
    cout << dp[n] << endl;

    return 0;
}
