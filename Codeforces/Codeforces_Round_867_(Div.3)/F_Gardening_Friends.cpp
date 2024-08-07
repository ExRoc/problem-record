#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int T, n, u, v;
LL ans, k, c;
vector<int> G[maxn];
int dis1[maxn], disu[maxn], disv[maxn];

void dfs(int root, int fa, int dis[maxn]) {
    for (int pos : G[root]) {
        if (pos == fa) {
            continue;
        }
        dis[pos] = dis[root] + 1;
        dfs(pos, root, dis);
    }
}

int findMaxDisPos(int root, int dis[maxn]) {
    dis[root] = 0;
    dfs(root, root, dis);
    int ret = root;
    for (int i = 1; i <= n; ++i) {
        if (dis[i] > dis[ret]) {
            ret = i;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n >> k >> c;
        for (int i = 1; i <= n; ++i) {
            G[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        u = findMaxDisPos(1, dis1);
        v = findMaxDisPos(u, disu);
        findMaxDisPos(u, disv);
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, max(disu[i], disv[i]) * k - c * dis1[i]);
        }
        cout << ans << endl;
    }

    return 0;
}
