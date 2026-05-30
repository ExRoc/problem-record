#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;

void dfs(int root, int fa, const vector<vector<int>>& G,
         vector<vector<long long>>& dp, const vector<int>& a) {
    dp[root][0] = 0;
    dp[root][1] = a[root];
    bool hasBlack = false;
    for (int pos : G[root]) {
        if (pos == fa) {
            continue;
        }
        dfs(pos, root, G, dp, a);
        long long mn = min(dp[pos][0], dp[pos][1]);
        dp[root][1] += mn;
        dp[root][0] += mn;
        if (mn == dp[pos][1]) {
            hasBlack = true;
        }
    }
    if (hasBlack) {
        return;
    }
    if (G[root].empty()) {
        dp[root][0] = INF;
        return;
    }
    long long origin = dp[root][0];
    dp[root][0] = INF;
    for (int pos : G[root]) {
        if (pos == fa) {
            continue;
        }
        dp[root][0] = min(dp[root][0], origin - dp[pos][0] + dp[pos][1]);
    }
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> G(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(2));
    dfs(1, 1, G, dp, a);
    cout << min(dp[1][0], dp[1][1]) << '\n';

    return 0;
}