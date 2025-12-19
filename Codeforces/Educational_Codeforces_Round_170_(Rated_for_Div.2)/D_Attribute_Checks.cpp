#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 5000 + 100;
int n, m, r, cnt, ans;
int dp[maxn], ddp[maxn];

void sumddp() {
    dp[0] += ddp[0];
    for (int i = 1; i <= cnt; ++i) {
        ddp[i] += ddp[i - 1];
        dp[i] += ddp[i];
    }
    memset(ddp, 0, sizeof(ddp));
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> r;
        if (r == 0) {
            ++cnt;
            sumddp();
            for (int j = cnt; j > 0; --j) {
                dp[j] = max(dp[j], dp[j - 1]);
            }
        } else if (r > 0) {
            if (r <= cnt) {
                ++ddp[r];
            }
        } else {
            r = -r;
            if (r <= cnt) {
                ++ddp[0];
                --ddp[cnt - r + 1];
            }
        }
    }
    sumddp();
    for (int i = 0; i <= m; ++i) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;

    return 0;
}
