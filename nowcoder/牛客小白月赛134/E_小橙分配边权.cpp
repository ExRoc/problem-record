#include <bits/stdc++.h>
using namespace std;

struct Node {
    int pos, idx;
    long long dis;

    Node() {}

    Node(int pos, long long dis, int idx) : pos(pos), dis(dis), idx(idx) {}

    bool operator<(const Node& other) const { return dis > other.dis; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1);
    int s = 0;
    int cnt0 = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            s = i;
            ++cnt0;
        }
    }
    if (cnt0 == 0) {
        cout << -1 << '\n';
        return 0;
    }
    vector<vector<Node>> G(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(Node(v, 1e9, i));
        G[v].push_back(Node(u, 1e9, i));
    }
    priority_queue<Node> que;
    que.push(Node(s, 0, 0));
    vector<bool> vis(n + 1, false);
    vis[s] = true;
    vector<long long> ans(m, 1e9);
    while (!que.empty()) {
        Node tmp = que.top();
        que.pop();
        for (Node& node : G[tmp.pos]) {
            if (vis[node.pos]) {
                continue;
            }
            vis[node.pos] = true;
            que.push(Node(node.pos, a[node.pos], 0));
            ans[node.idx] = a[node.pos] - tmp.dis;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (Node& node : G[i]) {
            node.dis = ans[node.idx];
            if (node.dis > 1000000000 || node.dis < 0) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    const long long INF = 0x3f3f3f3f3f3f3f3f;
    vector<long long> dis(n + 1, INF);
    vis.assign(n + 1, false);
    dis[s] = 0;
    que.push(Node(s, 0, 0));
    while (!que.empty()) {
        Node tmp = que.top();
        que.pop();
        if (vis[tmp.pos]) {
            continue;
        }
        vis[tmp.pos] = true;
        for (const Node& node : G[tmp.pos]) {
            if (tmp.dis + node.dis < dis[node.pos]) {
                dis[node.pos] = tmp.dis + node.dis;
                que.push(Node(node.pos, dis[node.pos], 0));
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (dis[i] != a[i]) {
            cout << -1 << '\n';
            return 0;
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}