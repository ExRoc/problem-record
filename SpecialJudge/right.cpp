#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1000 + 100;
int n, m, ans;
int d[maxn];
vector<int> dd;
int dp[maxn][maxn][2];

int solve(vector<int>& d) {
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    int n = d.size() - 1;
    for (int i = 1; i <= n; ++i) {
        int top = min((i + 1) / 2, m);
        dp[i][0][0] = 0;
        for (int j = 1; j <= top; ++j) {
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]);
            if (dp[i - 1][j - 1][0] != -1) {
                dp[i][j][1] = dp[i - 1][j - 1][0] + d[i];
            }
        }
    }
    int top = min((n + 1) / 2, m);
    return max(dp[n][top][0], dp[n][top][1]);
}

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
    if (n == 1) {
        cout << d[1] << endl;
        return 0;
    }
    dd.push_back(0);
    for (int i = 1; i < n; ++i) {
        dd.push_back(d[i]);
    }
    ans = solve(dd);
    dd.clear();
    dd.push_back(0);
    for (int i = 2; i <= n; ++i) {
        dd.push_back(d[i]);
    }
    ans = max(ans, solve(dd));
    cout << ans << endl;

    return 0;
}
