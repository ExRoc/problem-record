#include <bits/stdc++.h>
using namespace std;

struct Node {
    int pos, dis;

    Node() {}

    Node(int pos, int dis) : pos(pos), dis(dis) {}

    bool operator<(const Node& other) const { return dis > other.dis; }
};

int main() {
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<Node>> G(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(Node(v, w));
        G[v].push_back(Node(u, w));
    }
    const int INF = 0x3f3f3f3f;
    vector<int> dis(n + 1, INF);
    priority_queue<Node> que;
    for (int i = 0; i < k; ++i) {
        int p, t;
        cin >> p >> t;
        dis[p] = t;
        que.push(Node(p, t));
    }
    int ans = 0;
    vector<bool> vis(n + 1, false);
    while (!que.empty()) {
        Node tmp = que.top();
        que.pop();
        if (vis[tmp.pos]) {
            continue;
        }
        vis[tmp.pos] = true;
        ans = max(ans, tmp.dis);
        for (Node& node : G[tmp.pos]) {
            if (dis[node.pos] > tmp.dis + node.dis) {
                dis[node.pos] = tmp.dis + node.dis;
                que.push(Node(node.pos, dis[node.pos]));
            }
        }
    }
    cout << ans << '\n';

    return 0;
}