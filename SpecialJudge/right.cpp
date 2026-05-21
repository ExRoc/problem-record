#include <bits/stdc++.h>
using namespace std;

long long dfs(int root, int fa, vector<vector<int>>& G, int status,
              vector<long long>& a, string& s) {
    long long sum = 0;
    int bit = 0;
    for (int pos : G[root]) {
        if (pos == fa) {
            continue;
        }
        sum += dfs(pos, root, G, status, a, s);
        bit |= ((status >> pos) & 1);
    }
    if ((bit == 1 && s[root] == '1') || ((status >> root) && 1) == 1) {
        sum += a[root];
    }
    return sum;
}

long long solve(int status, int n, vector<vector<int>>& G, vector<long long>& a,
                string& s) {
    return dfs(0, 0, G, status, a, s);
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        string s;
        cin >> s;
        vector<vector<int>> G(n);
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        long long ans = 0;
        for (int i = 0; i < (1 << n); ++i) {
            long long ansTmp = solve(i, n, G, a, s);
            ans = max(ans, ansTmp);
        }
        cout << ans << '\n';
    }

    return 0;
}