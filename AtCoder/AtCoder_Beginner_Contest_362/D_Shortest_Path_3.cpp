#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
struct Node {
    int pos;
    LL dis;
    Node() {}
    Node(int pos, LL dis) : pos(pos), dis(dis) {}
};

bool operator<(const Node& a, const Node& b) {
    return a.dis > b.dis;
}

int n, m, u, v, w;
LL num[maxn], dis[maxn];
vector<Node> G[maxn];
priority_queue<Node> que;

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        G[u].push_back(Node(v, w));
        G[v].push_back(Node(u, w));
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = num[1];
    que.push(Node(1, num[1]));
    while (!que.empty()) {
        Node tmp = que.top();
        que.pop();
        if (tmp.dis > dis[tmp.pos]) {
            continue;
        }
        for (Node& node : G[tmp.pos]) {
            LL d = tmp.dis + node.dis + num[node.pos];
            if (d < dis[node.pos]) {
                dis[node.pos] = d;
                que.push(Node(node.pos, d));
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << dis[i] << " ";
    }
    cout << endl;

    return 0;
}
