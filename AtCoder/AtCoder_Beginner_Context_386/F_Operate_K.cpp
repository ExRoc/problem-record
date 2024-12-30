#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 500000 + 100;
int k, slen, tlen;
char s[maxn], t[maxn];
int dp[maxn][100];

int main() {
    ios::sync_with_stdio(false);

    cin >> k >> (s + 1) >> (t + 1);
    slen = strlen(s + 1);
    tlen = strlen(t + 1);
    if (abs(slen - tlen) > k) {
        cout << "No" << endl;
        return 0;
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0][k] = 0;
    for (int i = 0; i <= slen; ++i) {
        for (int kk = -k; kk <= k; ++kk) {
            int j = i + kk;
            if (j < 0 || j > tlen) {
                continue;
            }
            int kkk = kk + k;
            if (i > 0 && kkk + 1 <= 2 * k) {
                dp[i][kkk] = min(dp[i][kkk], dp[i - 1][kkk + 1] + 1);
            }
            if (j > 0 && kkk - 1 >= 0) {
                dp[i][kkk] = min(dp[i][kkk], dp[i][kkk - 1] + 1);
            }
            if (i > 0 && j > 0) {
                dp[i][kkk] = min(dp[i][kkk], dp[i - 1][kkk] + (s[i] != t[j]));
            }
        }
    }
    cout << (dp[slen][k + tlen - slen] <= k ? "Yes" : "No") << endl;

    return 0;
}
