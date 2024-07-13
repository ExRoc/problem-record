#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 500 + 100;
int n, L, R;
int dp[maxn][maxn];
int sum[maxn][2];
char str[maxn];

int main() {
    ios::sync_with_stdio(false);

    scanf("%d%d%d", &n, &L, &R);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; ++i) {
        sum[i][0] = sum[i - 1][0];
        sum[i][1] = sum[i - 1][1];
        ++sum[i][str[i] - '0'];
    }
    for (int len = 1; len <= n; ++len) {
        for (int l = 1; l + len - 1 <= n; ++l) {
            int r = l + len - 1;
            for (int m = l; m < r; ++m) {
                int c0 = sum[m][0] - sum[l - 1][0];
                int c1 = sum[r][1] - sum[m][1];
                if (L <= abs(c0 - c1) && abs(c0 - c1) <= R) {
                    dp[l][r] = max(dp[l][r], dp[l][m] + dp[m + 1][r] + 1);
                }
            }
        }
    }
    printf("%d\n", dp[1][n]);

    return 0;
}
