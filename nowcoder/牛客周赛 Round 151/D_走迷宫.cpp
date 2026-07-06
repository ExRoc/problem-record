#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y;

    Node() {}

    Node(int x, int y) : x(x), y(y) {}

    bool operator<(const Node& other) const { return false; }
};

bool in(int x1, int y1, int a, int b, int n, int m,
        const vector<vector<int>>& sum) {
    int x2 = x1 + a - 1;
    int y2 = y1 + b - 1;
    if (x1 < 1 || x1 > n || y1 < 1 || y1 > m || x2 < 1 || x2 > n || y2 < 1 ||
        y2 > m) {
        return false;
    }
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] +
               sum[x1 - 1][y1 - 1] ==
           0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int a, b;
        cin >> a >> b;
        vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
        Node s, t;
        for (int i = 1; i <= n; ++i) {
            string str;
            cin >> str;
            for (int j = 1; j <= m; ++j) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
                if (str[j - 1] == '#') {
                    ++sum[i][j];
                } else if (str[j - 1] == 'S') {
                    s = Node(i, j);
                } else if (str[j - 1] == 'E') {
                    t = Node(i, j);
                }
            }
        }
        queue<Node> que;
        que.push(s);
        vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
        vis[s.x][s.y] = true;
        while (!que.empty()) {
            Node tmp = que.front();
            que.pop();
            for (int i = 0; i < 4; ++i) {
                int x = tmp.x + dir[i][0];
                int y = tmp.y + dir[i][1];
                if (in(x, y, a, b, n, m, sum) && !vis[x][y]) {
                    vis[x][y] = true;
                    que.push(Node(x, y));
                }
            }
        }
        if (vis[t.x][t.y]) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }

    return 0;
}