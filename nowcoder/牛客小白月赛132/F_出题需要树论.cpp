#include <bits/stdc++.h>
using namespace std;

long long dfs1(int root, int fa, long long sum, vector<vector<int>>& G,
               vector<int>& w, vector<long long>& dp) {
    sum += w[root];
    long long mx = 0;
    long long sec = 0;
    vector<long long> mxTmp(G[root].size(), 0);
    for (int i = 0; i < (int)G[root].size(); ++i) {
        int pos = G[root][i];
        if (pos == fa) {
            continue;
        }
        long long tmp = dfs1(pos, root, sum, G, w, dp);
        mxTmp[i] = tmp;
        if (tmp > mx) {
            sec = mx;
            mx = tmp;
        } else if (tmp > sec) {
            sec = tmp;
        }
    }
    for (int i = 0; i < (int)G[root].size(); ++i) {
        int pos = G[root][i];
        if (pos == fa) {
            continue;
        }
        if (mxTmp[i] == mx) {
            dp[pos] = sec;
        } else {
            dp[pos] = mx;
        }
    }
    return max(mx, sum);
}

void dfs2(int root, int fa, vector<vector<int>>& G, vector<long long>& dp) {
    for (int pos : G[root]) {
        if (pos == fa) {
            continue;
        }
        dp[pos] = max(dp[pos], dp[root]);
        dfs2(pos, root, G, dp);
    }
}

void dfs3(int root, int fa, long long sum, int x, vector<vector<int>>& G,
          vector<int>& w, vector<long long>& dp) {
    sum += w[root];
    dp[root] = sum;
    for (int pos : G[root]) {
        if (pos == fa) {
            continue;
        }
        dfs3(pos, root, sum, x, G, w, dp);
        dp[root] = max(dp[root], dp[pos]);
    }
    dp[root] = dp[root] - w[root] + (w[root] ^ x);
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<int> w(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> w[i];
        }
        vector<vector<int>> G(n + 1);
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<long long> dp1(n + 1, 0);
        dfs1(1, 1, 0, G, w, dp1);
        dfs2(1, 1, G, dp1);
        vector<long long> dp2(n + 1, 0);
        dfs3(1, 1, 0, x, G, w, dp2);
        long long ans = LONG_LONG_MAX;
        for (int i = 1; i <= n; ++i) {
            ans = min(ans, max(dp1[i], dp2[i]));
        }
        cout << ans << '\n';
    }

    return 0;
}