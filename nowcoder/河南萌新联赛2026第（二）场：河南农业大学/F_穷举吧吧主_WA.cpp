#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long sum, cnt;

    Node() {}

    Node(long long _sum, long long _cnt) : sum(_sum), cnt(_cnt) {}

    bool operator<(const Node& other) const {
        return (__int128_t)sum * other.cnt < (__int128_t)other.sum * cnt;
    }
};

void dfs(int root, int fa, const vector<vector<int>>& G, vector<Node>& dp,
         Node& ans, const vector<long long>& a) {
    dp[root] = Node(a[root], 1);
    Node pre(0, 0);
    for (int pos : G[root]) {
        if (pos == fa) {
            continue;
        }
        dfs(pos, root, G, dp, ans, a);
        Node tmp(dp[pos].sum + a[root], dp[pos].cnt + 1);
        dp[root] = max(dp[root], tmp);
        tmp = Node(tmp.sum + pre.sum, tmp.cnt + pre.cnt);
        ans = max(ans, tmp);
        if (pre.cnt == 0) {
            pre = dp[pos];
        } else {
            pre = max(pre, dp[pos]);
        }
    }
    if (dp[root].cnt > 1) {
        ans = max(ans, dp[root]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1);
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
        Node ans(0, 1);
        vector<Node> dp(n + 1);
        dfs(1, 1, G, dp, ans, a);
        printf("%.2lf\n", 1.0 * ans.sum / ans.cnt);
    }

    return 0;
}