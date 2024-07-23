#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 500000 + 100;
int T, n, u, v;
LL ans;
vector<int> G[maxn];
vector<LL> Tmp[maxn];
LL num[maxn], dp[maxn];

void dfs(int root, int fa) {
    vector<LL>& tmp = Tmp[root];
    tmp.clear();
    dp[root] = num[root];
    for (int pos : G[root]) {
        if (pos == fa) {
            continue;
        }
        dfs(pos, root);
        tmp.push_back(dp[pos]);
    }
    int son = tmp.size();
    sort(tmp.begin(), tmp.end(), greater<LL>());
    if (son >= 1) {
        ans = max(ans, tmp[0] + num[root]);
        dp[root] = max(dp[root], tmp[0]);
    }
    if (son >= 2) {
        ans = max(ans, tmp[0] + tmp[1]);
        if (root != 1) {
            dp[root] = max(dp[root], num[root] + tmp[0] + tmp[1]);
        }
    }
    if (son >= 3) {
        LL ttmp = num[root];
        for (int i = 0; i < son; ++i) {
            if (i < 3 || tmp[i] >= 0) {
                ttmp += tmp[i];
            }
        }
        dp[root] = max(dp[root], ttmp);
        ans = max(ans, ttmp);
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n;
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            G[i].clear();
            cin >> num[i];
            ans = max(ans, num[i]);
        }
        for (int i = 1; i < n; ++i) {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1, 1);
        cout << ans << endl;
    }

    return 0;
}
