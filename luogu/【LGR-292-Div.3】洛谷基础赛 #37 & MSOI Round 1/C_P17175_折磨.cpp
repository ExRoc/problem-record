#include <bits/stdc++.h>
using namespace std;

struct Node {
    int a, pos;

    Node() {}

    Node(int _a, int _pos) : a(_a), pos(_pos) {}

    bool operator<(const Node& other) const { return a < other.a; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, E, M, A;
    cin >> N >> E >> M >> A;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> G(N + 1);
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    priority_queue<Node> que;
    vector<bool> vis(N + 1, false);
    vis[A] = true;
    for (int i = 0; i < M; ++i) {
        int pos;
        cin >> pos;
        que.push(Node(a[pos], pos));
    }
    while (!que.empty()) {
        Node node = que.top();
        que.pop();
        vis[node.pos] = true;
        for (int pos : G[node.pos]) {
            if (a[pos] <= node.a && !vis[pos]) {
                a[pos] = node.a;
                vis[pos] = true;
                que.push(Node(a[pos], pos));
            }
        }
    }
    int ans = 0;
    for (int pos : G[A]) {
        if (vis[pos]) {
            ++ans;
        }
    }
    cout << ans << '\n';

    return 0;
}