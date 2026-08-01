#include <bits/stdc++.h>
using namespace std;

struct Node {
    int pos, cnt;
    long long dis;

    Node() {}

    Node(int _pos, int _cnt, long long _dis)
        : pos(_pos), cnt(_cnt), dis(_dis) {}

    bool operator<(const Node& other) const { return dis > other.dis; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<Node>> G(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        G[u].push_back(Node(v, 1, w));
    }
    const long long INF = 0x3f3f3f3f3f3f3f3f;
    vector<vector<long long>> dis(N + 1, vector<long long>(N + 1, INF));
    vector<vector<bool>> vis(N + 1, vector<bool>(N + 1, false));
    dis[1][1] = 0;
    priority_queue<Node> que;
    que.push(Node(1, 1, 0));
    while (!que.empty()) {
        Node node = que.top();
        que.pop();
        if (node.cnt == N) {
            continue;
        }
        if (vis[node.pos][node.cnt]) {
            continue;
        }
        vis[node.pos][node.cnt] = true;
        for (const Node& nextPos : G[node.pos]) {
            if (dis[nextPos.pos][node.cnt + 1] > node.dis + nextPos.dis) {
                dis[nextPos.pos][node.cnt + 1] = node.dis + nextPos.dis;
                que.push(
                    Node(nextPos.pos, node.cnt + 1, node.dis + nextPos.dis));
            }
        }
    }
    long long ans = INF;
    for (int k = 2; k <= N - k; ++k) {
        ans = min(ans, dis[N][k]);
    }
    if (ans == INF) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }

    return 0;
}