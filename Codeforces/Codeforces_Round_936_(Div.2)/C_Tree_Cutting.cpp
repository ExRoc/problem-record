#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
int T, n, k, u, v, kk;
vector<int> G[maxn];
int son[maxn];

bool dfs(int root, int fa, int x) {
    son[root] = 1;
    for (int pos : G[root]) {
        if (pos == fa) {
            continue;
        }
        bool flag = dfs(pos, root, x);
        if (!flag) {
            son[root] += son[pos];
        }
    }
    if (kk == k) {
        return false;
    }
    bool ret = (root != 1 && son[root] >= x);
    if (ret) {
        ++kk;
    }
    return ret;
}

bool judge(int x) {
    kk = 0;
    dfs(1, 1, x);
    return kk == k && son[1] >= x;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            G[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int low = 1;
        int high = n;
        int mid;
        while (high - low > 1) {
            mid = (high + low) >> 1;
            if (judge(mid)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        cout << low << endl;
    }

    return 0;
}
