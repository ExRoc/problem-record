#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int pos;
    vector<long long> dis;

    Edge() {}

    Edge(int pos, const vector<long long>& dis) : pos(pos), dis(dis) {}

    bool operator<(const Edge& other) const { return false; }
};

struct Node {
    int pos, status;
    long long dis;

    Node() {}

    Node(int pos, int status, long long dis)
        : pos(pos), status(status), dis(dis) {}

    bool operator<(const Node& other) const { return dis > other.dis; }
};

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, k, s, t;
        cin >> n >> k >> s >> t;
        vector<bool> canChange(n + 1, false);
        for (int i = 0; i < k; ++i) {
            int p;
            cin >> p;
            canChange[p] = true;
        }
        vector<vector<Edge>> G(n + 1, vector<Edge>());
        for (int i = 1; i < n; ++i) {
            int u, v, a, b;
            cin >> u >> v >> a >> b;
            G[u].push_back(Edge(v, {a, b}));
            G[v].push_back(Edge(u, {a, b}));
        }
        const long long INF = 0x3f3f3f3f3f3f3f3f;
        vector<vector<long long>> dis(n + 1, vector<long long>(2, INF));
        dis[s][0] = 0;
        priority_queue<Node> que;
        que.push(Node(s, 0, 0));
        if (canChange[s]) {
            dis[s][1] = 0;
            que.push(Node(s, 1, 0));
        }
        vector<vector<bool>> vis(n + 1, vector<bool>(2, false));
        while (!que.empty()) {
            Node tmp = que.top();
            que.pop();
            if (vis[tmp.pos][tmp.status]) {
                continue;
            }
            vis[tmp.pos][tmp.status] = true;
            for (Edge& edge : G[tmp.pos]) {
                long long dTmp = tmp.dis + edge.dis[tmp.status];
                if (dTmp < dis[edge.pos][tmp.status]) {
                    dis[edge.pos][tmp.status] = dTmp;
                    que.push(Node(edge.pos, tmp.status, dTmp));
                }
                if (canChange[edge.pos]) {
                    if (dTmp < dis[edge.pos][tmp.status ^ 1]) {
                        dis[edge.pos][tmp.status ^ 1] = dTmp;
                        que.push(Node(edge.pos, tmp.status ^ 1, dTmp));
                    }
                }
            }
        }
        cout << min(dis[t][0], dis[t][1]) << '\n';
    }

    return 0;
}