#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y, s;

    Node() {}

    Node(int x, int y, int s) : x(x), y(y), s(s) {}

    bool operator<(const Node& other) const { return false; }
};

bool in(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> G(n);
    Node s, t;
    for (int i = 0; i < n; ++i) {
        cin >> G[i];
        for (int j = 0; j < m; ++j) {
            if (G[i][j] == 'S') {
                s = Node(i, j, 0);
            } else if (G[i][j] == 'T') {
                t = Node(i, j, 0);
            }
        }
    }
    const int INF = 0x3f3f3f3f;
    vector<vector<vector<int>>> dis(
        n, vector<vector<int>>(m, vector<int>(2, INF)));
    dis[s.x][s.y][s.s] = 0;
    const vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<Node> que;
    que.push(s);
    while (!que.empty()) {
        Node node = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i) {
            Node tmp = Node(node.x + dir[i][0], node.y + dir[i][1], node.s);
            if (in(tmp.x, tmp.y, n, m)) {
                if (G[tmp.x][tmp.y] != '#' && dis[tmp.x][tmp.y][tmp.s] == INF) {
                    dis[tmp.x][tmp.y][tmp.s] = dis[node.x][node.y][node.s] + 1;
                    que.push(tmp);
                }
                if (tmp.s == 0) {
                    tmp.s = 1;
                    if (dis[tmp.x][tmp.y][tmp.s] == INF) {
                        dis[tmp.x][tmp.y][tmp.s] =
                            dis[node.x][node.y][node.s] + 1;
                        que.push(tmp);
                    }
                }
            }
        }
    }
    int ans = min(dis[t.x][t.y][0], dis[t.x][t.y][1]);
    cout << (ans == INF ? -1 : ans) << '\n';

    return 0;
}