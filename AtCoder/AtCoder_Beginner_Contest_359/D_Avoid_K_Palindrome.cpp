#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1000 + 100;
const int maxm = 60000 + 10;
const int maxk = 10 + 10;
const LL MOD = 998244353;
int n, k;
LL ans;
char str[maxn];
LL dp[maxn][maxm];
int pow3[maxk];
bool isP[maxm];

bool isPP(int x) {
    for (int i = 0; i < k; ++i) {
        if (x / pow3[i] % 3 == 0) {
            return false;
        }
        if (x / pow3[i] % 3 != x / pow3[k - i - 1] % 3) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);

    pow3[0] = 1;
    for (int i = 1; i < maxk; ++i) {
        pow3[i] = pow3[i - 1] * 3;
    }
    cin >> n >> k;
    cin >> (str + 1);
    for (int i = 0; i < pow3[k]; ++i) {
        isP[i] = isPP(i);
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < pow3[k]; ++j) {
            if (isP[j] || j % 3 == 0) {
                continue;
            }
            if (str[i] == 'A' && j % 3 != 1) {
                continue;
            }
            if (str[i] == 'B' && j % 3 != 2) {
                continue;
            }
            dp[i][j] = (dp[i - 1][j / 3 + pow3[k - 1]] +
                        dp[i - 1][j / 3 + pow3[k - 1] * 2] + dp[i - 1][j / 3]) %
                       MOD;
        }
    }
    for (int j = 0; j < pow3[k]; ++j) {
        ans = (ans + dp[n][j]) % MOD;
    }
    cout << ans << endl;

    return 0;
}
