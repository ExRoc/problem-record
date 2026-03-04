#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long LL;
const int maxn = 200000 + 100;
const LL MOD = 998244353;
struct Node {
    int idx;
    LL x;
};

bool operator<(const Node& a, const Node& b) {
    return a.x < b.x;
}

int T, n, m, u, v;
LL ans;
LL num[maxn];
Node node[maxn];
map<LL, LL> dp[maxn];
map<LL, LL>::iterator it;
vector<int> G[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i].clear();
            G[i].clear();
        }
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
            node[i] = {i, num[i]};
        }
        sort(node + 1, node + 1 + n);
        for (int i = 1; i <= m; ++i) {
            cin >> u >> v;
            G[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i) {
            for (int pos : G[node[i].idx]) {
                LL& tmp = dp[node[i].idx][num[pos]];
                ++tmp;
                it = dp[pos].find(node[i].x - num[pos]);
                if (it != dp[pos].end()) {
                    tmp = (tmp + it->second) % MOD;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (it = dp[i].begin(); it != dp[i].end(); ++it) {
                ans = (ans + it->second) % MOD;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
