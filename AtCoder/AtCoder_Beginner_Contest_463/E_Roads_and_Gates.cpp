#include <bits/stdc++.h>
using namespace std;

struct Node {
    int pos;
    long long d;

    Node() {}

    Node(int pos, long long d) : pos(pos), d(d) {}

    bool operator<(const Node& other) const { return d > other.d; }
};

int main() {
    ios::sync_with_stdio(false);

    int N, M;
    long long Y;
    cin >> N >> M >> Y;
    vector<vector<Node>> G(N + 2);
    for (int i = 0; i < M; ++i) {
        int u, v;
        long long T;
        cin >> u >> v >> T;
        G[u].push_back(Node(v, T));
        G[v].push_back(Node(u, T));
    }
    for (int i = 1; i <= N; ++i) {
        long long X;
        cin >> X;
        G[i].push_back(Node(0, X));
        G[N + 1].push_back(Node(i, X));
    }
    G[0].push_back(Node(N + 1, Y));
    priority_queue<Node> que;
    que.push(Node(1, 0));
    const long long INF = 0x3f3f3f3f3f3f3f3f;
    vector<long long> dis(N + 2, INF);
    vector<bool> vis(N + 2);
    while (!que.empty()) {
        Node tmp = que.top();
        que.pop();
        if (vis[tmp.pos]) {
            continue;
        }
        vis[tmp.pos] = true;
        for (Node node : G[tmp.pos]) {
            if (dis[node.pos] > tmp.d + node.d) {
                dis[node.pos] = tmp.d + node.d;
                que.push(Node(node.pos, dis[node.pos]));
            }
        }
    }
    for (int i = 2; i <= N; ++i) {
        cout << dis[i] << ' ';
    }
    cout << '\n';

    return 0;
}