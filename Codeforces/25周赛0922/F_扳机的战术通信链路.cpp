#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int pos;
    long long f, w;

    Edge() {}

    Edge(int pos, long long f, long long w) : pos(pos), f(f), w(w) {}
};

struct Node {
    int pos, k;
    long long dis;

    Node() {}

    Node(int pos, int k, long long dis) : pos(pos), k(k), dis(dis) {}

    bool operator<(const Node& other) const { return dis > other.dis; }
};

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<Edge>> G(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v, f, w;
        cin >> u >> v >> f >> w;
        G[u].push_back(Edge(v, f, w));
        G[v].push_back(Edge(u, f, w));
    }
    const long long INF = 0x3f3f3f3f3f3f3f3f;
    vector<vector<long long>> dis(N + 1, vector<long long>(K + 1, INF));
    vector<vector<bool>> vis(N + 1, vector<bool>(K + 1, false));
    priority_queue<Node> que;
    que.push(Node(1, 0, 0));
    dis[1][0] = 0;
    while (!que.empty()) {
        Node tmp = que.top();
        que.pop();
        if (vis[tmp.pos][tmp.k]) {
            continue;
        }
        vis[tmp.pos][tmp.k] = true;
        for (const Edge& e : G[tmp.pos]) {
            if (dis[e.pos][tmp.k] > dis[tmp.pos][tmp.k] + e.f) {
                dis[e.pos][tmp.k] = dis[tmp.pos][tmp.k] + e.f;
                que.push(Node(e.pos, tmp.k, dis[e.pos][tmp.k]));
            }
            if (tmp.k < K && e.w != -1 &&
                dis[e.pos][tmp.k + 1] > dis[tmp.pos][tmp.k] + e.w) {
                dis[e.pos][tmp.k + 1] = dis[tmp.pos][tmp.k] + e.w;
                que.push(Node(e.pos, tmp.k + 1, dis[e.pos][tmp.k + 1]));
            }
        }
    }
    long long ans = INF;
    for (int k = 0; k <= K; ++k) {
        ans = min(ans, dis[N][k]);
    }
    cout << ans << '\n';

    return 0;
}