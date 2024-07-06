#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL Limit = 1000000000000LL;
LL T, n, m, k;
char str[12][50];
LL bit[531442][12], twoCnt[531442];
LL dp[21][531442], ans[21], pow3[21], fac[50];

int getBit(int x, int i) {
    return x / pow3[i] % 3;
}

void init() {
    fac[0] = 1;
    pow3[0] = 1;
    for (int i = 1; i <= 20; ++i) {
        pow3[i] = pow3[i - 1] * 3;
        fac[i] = fac[i - 1] * i;
    }
    for (int i = 0; i < 531442; ++i) {
        int cnt = 0;
        for (int j = 0; j < 12; ++j) {
            bit[i][j] = getBit(i, j);
            if (bit[i][j] == 2) {
                ++cnt;
            }
        }
        twoCnt[i] = cnt;
    }
}

int getBit2(int x, int i) {
    return bit[x][i];
}

int setBit(int x, int i, int y) {
    x -= getBit2(x, i) * pow3[i];
    x += y * pow3[i];
    return x;
}

string toString(int x) {
    string str;
    for (int i = 0; i < n; ++i) {
        str += (char)('0' + getBit2(x, i));
    }
    return str;
}

int main() {
    ios::sync_with_stdio(false);

    init();
    scanf("%I64d", &T);
    while (T--) {
        scanf("%I64d%I64d%I64d", &n, &m, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%s", str[i]);
        }
        dp[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            memset(dp[i], 0, sizeof(LL) * pow3[n]);
        }
        for (int i = 0; i < m; ++i) {
            int now = i + 1;
            int pre = i;
            for (int j = 0; j < pow3[n]; ++j) {
                if (dp[pre][j] == 0 || twoCnt[j] > k) {
                    continue;
                }
                int jj = j;
                for (int k = 0; k < n; ++k) {
                    if (str[k][i] == 'Q' && getBit2(jj, k) != 2) {
                        jj = setBit(jj, k, 1);
                        dp[now][setBit(j, k, 2)] += dp[pre][j];
                    }
                }
                dp[now][jj] += dp[pre][j];
            }
        }
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < pow3[n]; ++i) {
            bool flag = true;
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (getBit2(i, j) == 1) {
                    flag = false;
                }
                if (getBit2(i, j) == 2) {
                    ++cnt;
                }
            }
            if (flag) {
                ans[cnt] += dp[m][i];
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
