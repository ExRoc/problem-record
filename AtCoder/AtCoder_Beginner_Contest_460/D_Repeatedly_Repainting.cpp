#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y;

    Node() {}

    Node(int x, int y) : x(x), y(y) {}

    bool in(int H, int W) { return x >= 0 && x < H && y >= 0 && y < W; }

    bool operator<(const Node& other) const { return false; }
};

int main() {
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }
    queue<Node> que;
    vector<vector<int>> dis(H, vector<int>(W, -1));
    const vector<vector<int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                     {0, 1},   {1, -1}, {1, 0},  {1, 1}};
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (S[i][j] == '#') {
                continue;
            }
            bool flag = false;
            for (int k = 0; k < 8; ++k) {
                Node tmp = Node(i + dir[k][0], j + dir[k][1]);
                if (tmp.in(H, W) && S[tmp.x][tmp.y] == '#') {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                que.push(Node(i, j));
                dis[i][j] = 0;
            }
        }
    }
    while (!que.empty()) {
        Node tmp = que.front();
        que.pop();
        for (int i = 0; i < 8; ++i) {
            Node pos = Node(tmp.x + dir[i][0], tmp.y + dir[i][1]);
            if (!pos.in(H, W)) {
                continue;
            }
            if (dis[pos.x][pos.y] == -1) {
                dis[pos.x][pos.y] = dis[tmp.x][tmp.y] ^ 1;
                que.push(pos);
            }
        }
    }
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (dis[i][j] == 1) {
                cout << '#';
            } else {
                cout << '.';
            }
        }
        cout << '\n';
    }

    return 0;
}