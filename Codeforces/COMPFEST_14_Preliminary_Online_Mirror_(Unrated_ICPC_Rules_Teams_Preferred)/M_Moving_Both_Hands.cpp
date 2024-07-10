#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
const LL INF = 0x3f3f3f3f3f3f3f3f;
struct Node {
    int pos, dir;
    LL dis;
    Node() {}
    Node(int pos, int dir, LL dis) : pos(pos), dir(dir), dis(dis) {}
};

bool operator<(const Node& a, const Node& b) {
    return a.dis > b.dis;
}

int n, m, u, v, w;
vector<Node> G[maxn];
LL dis[maxn][2];
priority_queue<Node> que;

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        dis[i][0] = dis[i][1] = INF;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v >> w;
        G[u].push_back(Node(v, 0, w));
        G[v].push_back(Node(u, 1, w));
    }
    dis[1][0] = 0;
    que.push(Node(1, 0, 0));
    while (!que.empty()) {
        Node tmp = que.top();
        que.pop();
        if (tmp.dis > dis[tmp.pos][tmp.dir]) {
            continue;
        }
        for (Node& node : G[tmp.pos]) {
            if (node.dir >= tmp.dir &&
                dis[node.pos][node.dir] > tmp.dis + node.dis) {
                dis[node.pos][node.dir] = tmp.dis + node.dis;
                que.push(Node(node.pos, node.dir, dis[node.pos][node.dir]));
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        LL d = min(dis[i][0], dis[i][1]);
        if (d == INF) {
            cout << -1 << " ";
        } else {
            cout << d << " ";
        }
    }
    cout << endl;

    return 0;
}
