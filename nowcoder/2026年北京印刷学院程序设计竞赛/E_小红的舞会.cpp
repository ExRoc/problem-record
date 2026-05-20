#include <bits/stdc++.h>
using namespace std;

void dfs(int root, int fa, const vector<vector<int>>& G, vector<long long>& a,
         const string& s, vector<vector<long long>>& dp) {
    for (int pos : G[root]) {
        if (pos == fa) {
            continue;
        }
        dfs(pos, root, G, a, s, dp);
        if (s[root] == '0') {
            dp[root][0] += max(dp[pos][0], dp[pos][1]);
            dp[root][1] += max(dp[pos][0], dp[pos][1]);
        } else {
            dp[root][0] += dp[pos][0];
            dp[root][1] += max(dp[pos][0], dp[pos][1]);
        }
    }
    dp[root][1] += a[root];
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        string s;
        cin >> s;
        s = ' ' + s;
        vector<vector<int>> G(n + 1);
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        dfs(1, 1, G, a, s, dp);
        // for (int i = 1; i <= n; ++i) {
        //     cout << dp[i][0] << " " << dp[i][1] << '\n';
        // }

        cout << max(dp[1][0], dp[1][1]) << '\n';
    }

    return 0;
}