#include <bits/stdc++.h>
using namespace std;

int id(const vector<int>& pos, int n) {
    int ret = 0;
    for (int i = 0; i < 4; ++i) {
        ret = ret * n + pos[i];
    }
    return ret;
}

bool in(const vector<int>& pos, int n) {
    for (int i = 0; i < 4; ++i) {
        if (pos[i] < 0 || pos[i] >= n) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> G(pow(n, 4), 0);
        const int INF = 0x3f3f3f3f;
        vector<int> dis(pow(n, 4), INF);
        vector<int> s, e;
        for (int i = 0; i < n * n; ++i) {
            string str;
            cin >> str;
            for (int j = 0; j < n * n; ++j) {
                int x = i % n;
                int y = j % n;
                int z = j / n;
                int t = i / n;
                vector<int> pos = {x, y, z, t};
                int idd = id(pos, n);
                if (str[j] == '#') {
                    G[idd] = 1;
                }
                if (str[j] == 'S') {
                    s = pos;
                }
                if (str[j] == 'E') {
                    e = pos;
                }
            }
        }
        queue<vector<int>> que;
        dis[id(s, n)] = 0;
        que.push(s);
        while (!que.empty()) {
            vector<int> tmp = que.front();
            que.pop();
            int idTmp = id(tmp, n);
            for (int i = 0; i < 4; ++i) {
                for (int j = -1; j <= 1; j += 2) {
                    vector<int> pos = tmp;
                    pos[i] += j;
                    if (!in(pos, n)) {
                        continue;
                    }
                    int idPos = id(pos, n);
                    if (G[idPos] == 1) {
                        continue;
                    }
                    if (dis[idTmp] + 1 < dis[idPos]) {
                        dis[idPos] = dis[idTmp] + 1;
                        que.push(pos);
                    }
                }
            }
        }
        cout << (dis[id(e, n)] == INF ? -1 : dis[id(e, n)]) << '\n';
    }

    return 0;
}