#include <bits/stdc++.h>
using namespace std;

struct Node {
    int pos, status;
    long long w;

    Node() {}

    Node(int pos, long long w, int status) : pos(pos), w(w), status(status) {}

    bool operator<(const Node& other) const { return w > other.w; }
};

int main() {
    ios::sync_with_stdio(false);

    int n, m, d;
    cin >> n >> m >> d;
    vector<vector<Node>> G(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(Node(v, w, 0));
        G[v].push_back(Node(u, w, 0));
    }
    priority_queue<Node> que;
    que.push(Node(1, 0, 0));
    const long long INF = 0x3f3f3f3f3f3f3f3f;
    vector<vector<long long>> dis(n + 1, vector<long long>(2, INF));
    vector<vector<bool>> vis(n + 1, vector<bool>(2, false));
    dis[1][0] = 0;
    while (!que.empty()) {
        Node tmp = que.top();
        que.pop();
        if (vis[tmp.pos][tmp.status]) {
            continue;
        }
        vis[tmp.pos][tmp.status] = true;
        for (const Node& node : G[tmp.pos]) {
            long long dd = tmp.w + node.w;
            if (dis[node.pos][tmp.status] > dd) {
                dis[node.pos][tmp.status] = dd;
                que.push(Node(node.pos, dd, tmp.status));
            }
            if (tmp.status == 1) {
                continue;
            }
            dd = tmp.w + node.w % d;
            if (dis[node.pos][1] > dd) {
                dis[node.pos][1] = dd;
                que.push(Node(node.pos, dd, 1));
            }
        }
    }
    cout << min(dis[n][0], dis[n][1]) << '\n';

    return 0;
}