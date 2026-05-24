#include <bits/stdc++.h>
using namespace std;

bool in(int x, int y, int N, int M) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<string> G(N);
        queue<pair<int, int>> que;
        const int INF = 0x3f3f3f3f;
        vector<vector<int>> dis_(N, vector<int>(M, INF));
        pair<int, int> s, t;
        for (int i = 0; i < N; ++i) {
            cin >> G[i];
            for (int j = 0; j < M; ++j) {
                if (G[i][j] == '*') {
                    dis_[i][j] = 0;
                    que.push(make_pair(i, j));
                } else if (G[i][j] == 'A') {
                    s = make_pair(i, j);
                } else if (G[i][j] == 'E') {
                    t = make_pair(i, j);
                }
            }
        }
        const vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!que.empty()) {
            pair<int, int> tmp = que.front();
            que.pop();
            for (const pair<int, int>& d : dir) {
                int x = tmp.first + d.first;
                int y = tmp.second + d.second;
                if (!in(x, y, N, M) || G[x][y] == '#') {
                    continue;
                }
                if (dis_[x][y] > dis_[tmp.first][tmp.second] + 1) {
                    dis_[x][y] = dis_[tmp.first][tmp.second] + 1;
                    que.push(make_pair(x, y));
                }
            }
        }
        vector<vector<int>> dis(N, vector<int>(M, INF));
        dis[s.first][s.second] = 0;
        que.push(s);
        while (!que.empty()) {
            pair<int, int> tmp = que.front();
            que.pop();
            for (const pair<int, int>& d : dir) {
                int x = tmp.first + d.first;
                int y = tmp.second + d.second;
                int newDis = dis[tmp.first][tmp.second] + 1;
                if (!in(x, y, N, M) || G[x][y] == '#' || newDis >= dis_[x][y]) {
                    continue;
                }
                if (dis[x][y] > newDis) {
                    dis[x][y] = newDis;
                    que.push(make_pair(x, y));
                }
            }
        }
        cout << (dis[t.first][t.second] == INF ? -1 : dis[t.first][t.second])
             << '\n';
    }

    return 0;
}