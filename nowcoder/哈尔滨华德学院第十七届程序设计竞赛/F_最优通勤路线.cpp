#include <bits/stdc++.h>
using namespace std;

struct Node {
    int pos;
    long long dis;

    Node() {}

    Node(int pos, long long dis) : pos(pos), dis(dis) {}

    bool operator<(const Node& other) const { return dis > other.dis; }
};

void dij(int s, vector<vector<Node>>& G, vector<long long>& dis) {
    priority_queue<Node> que;
    que.push(Node(s, 0));
    dis[s] = 0;
    while (!que.empty()) {
        Node tmp = que.top();
        que.pop();
        for (Node node : G[tmp.pos]) {
            if (tmp.dis + node.dis < dis[node.pos]) {
                dis[node.pos] = tmp.dis + node.dis;
                que.push(Node(node.pos, dis[node.pos]));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<Node>> G(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        G[u].push_back(Node(v, w));
        G[v].push_back(Node(u, w));
    }
    int s, x, t;
    cin >> s >> x >> t;
    const long long INF = 0x3f3f3f3f3f3f3f3f;
    vector<long long> disS(n + 1, INF);
    dij(s, G, disS);
    vector<long long> disT(n + 1, INF);
    dij(t, G, disT);
    cout << disS[x] + disT[x] << '\n';

    return 0;
}