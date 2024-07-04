#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 300000 + 100;
const int INF = 0x3f3f3f3f;
int n, m, q, cmd, a, b;
int dis[2][maxn], fa[maxn], maxDis[maxn];
vector<int> G[maxn];
queue<int> que;

void init() {
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
}

int fnd(int x) {
    return x == fa[x] ? x : fa[x] = fnd(fa[x]);
}

void unit(int x, int y) {
    x = fnd(x);
    y = fnd(y);
    if (x != y) {
        maxDis[y] = max({maxDis[x], maxDis[y], (maxDis[x] + 1) / 2 + (maxDis[y] + 1) / 2 + 1});
        fa[x] = y;
    }
}

int bfs(int s, int dis[maxn]) {
    dis[s] = 0;
    que.push(s);
    int ret = s;
    while (!que.empty()) {
        int tmp = que.front();
        que.pop();
        if (dis[ret] < dis[tmp]) {
            ret = tmp;
        }
        for (int pos : G[tmp]) {
            if (dis[pos] > dis[tmp] + 1) {
                dis[pos] = dis[tmp] + 1;
                que.push(pos);
            }
        }
    }
    return ret;
}

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> n >> m >> q;
    init();
    memset(dis[0] + 1, 0x3f, sizeof(int) * n);
    memset(dis[1] + 1, 0x3f, sizeof(int) * n);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        unit(a, b);
    }
    for (int i = 1; i <= n; ++i) {
        if (dis[0][i] == INF) {
            a = bfs(i, dis[0]);
            b = bfs(a, dis[1]);
            maxDis[fnd(a)] = dis[1][b];
        }
    }
    while (q--) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> a;
            cout << maxDis[fnd(a)] << endl;
        } else {
            cin >> a >> b;
            unit(a, b);
        }
    }

    return 0;
}
