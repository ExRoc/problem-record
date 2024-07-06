#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int maxn = 22;
const int maxm = 13;
const int maxk = 21;
const int maxbit = 531500;
const LL Limit = 1e12;
int T, n, m, k;
LL ans[maxk], fac[maxk];
char str[maxm][maxn];
LL dp[maxn][maxbit];
int pow_3[maxm], bit_cnt_3[maxbit][3], bit_3[maxbit][maxm];

void Init() {
    pow_3[0] = 1;
    for (int i = 1; i < maxm; ++i) {
        pow_3[i] = pow_3[i - 1] * 3;
    }
    for (int i = 0; i < maxbit; ++i) {
        for (int j = 0; j < maxm; ++j) {
            ++bit_cnt_3[i][i / pow_3[j] % 3];
            bit_3[i][j] = i / pow_3[j] % 3;
        }
    }
    fac[0] = 1;
    for (int i = 1; i < maxk; ++i) {
        fac[i] = fac[i - 1] * i;
    }
}

int main() {
    ios::sync_with_stdio(false);

    Init();
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &m, &n, &k);
        for (int i = 0; i < m; ++i) {
            scanf("%s", str[i] + 1);
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < pow_3[m]; ++j) {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < pow_3[m]; ++j) {
                if (dp[i][j] == 0 || bit_cnt_3[j][2] > k) {
                    continue;
                }
                int tmp = 0;
                for (int kk = 0; kk < m; ++kk) {
                    if (str[kk][i + 1] == '.') {
                        continue;
                    }
                    if (bit_3[j][kk] == 0) {
                        tmp += pow_3[kk];
                    }
                    if (bit_3[j][kk] != 2) {
                        dp[i + 1][j + (2 - bit_3[j][kk]) * pow_3[kk]] +=
                            dp[i][j];
                    }
                }
                dp[i + 1][j + tmp] += dp[i][j];
            }
        }
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < pow_3[m]; ++i) {
            if (bit_cnt_3[i][1] == 0) {
                ans[bit_cnt_3[i][2]] += dp[n][i];
            }
        }
        for (int i = 1; i <= k; ++i) {
            __int128 Ans = (__int128)ans[i] * fac[i];
            if (Ans > Limit) {
                printf("%I64d%012I64d\n", (LL)(Ans / Limit), (LL)(Ans % Limit));
            } else {
                printf("%I64d\n", (LL)Ans);
            }
        }
    }

    return 0;
}
