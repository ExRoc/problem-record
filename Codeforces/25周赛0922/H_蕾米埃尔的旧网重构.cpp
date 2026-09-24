#include <bits/stdc++.h>
using namespace std;

void augment(int n, int root, vector<vector<int>>& G, vector<int>& lx,
             vector<int>& ly, vector<int>& My) {
    static const int INF = 0x3f3f3f3f;
    vector<int> slack(n + 1, INF);
    vector<bool> visy(n + 1, false);
    vector<int> pre(n + 1);
    int py;
    My[py = 0] = root;
    do {
        visy[py] = true;
        int x = My[py], yy;
        int delta = INF;
        for (int y = 1; y <= n; y++) {
            if (!visy[y]) {
                if (lx[x] + ly[y] - G[x][y] < slack[y]) {
                    slack[y] = lx[x] + ly[y] - G[x][y];
                    pre[y] = py;
                }
                if (slack[y] < delta) {
                    delta = slack[y];
                    yy = y;
                }
            }
        }
        for (int y = 0; y <= n; y++) {
            if (visy[y]) {
                lx[My[y]] -= delta;
                ly[y] += delta;
            } else {
                slack[y] -= delta;
            }
        }
        py = yy;
    } while (My[py] != -1);
    do {
        int Pre = pre[py];
        My[py] = My[Pre];
        py = Pre;
    } while (py != 0);
}

int KM(int n, vector<vector<int>>& G) {
    vector<int> lx(n + 1), ly(n + 1);
    vector<int> Mx(n + 1), My(n + 1);
    for (int i = 1; i <= n; i++) {
        lx[i] = ly[i] = 0;
        My[i] = -1;
        for (int j = 1; j <= n; j++) {
            lx[i] = max(lx[i], G[i][j]);
        }
    }
    int answer = 0;
    for (int root = 1; root <= n; root++) {
        augment(n, root, G, lx, ly, My);
    }
    for (int i = 1; i <= n; ++i) {
        Mx[My[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        answer += lx[i];
        answer += ly[i];
    }
    return answer;
}

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M1, M2;
    cin >> N >> M1 >> M2;
    if (M1 != M2) {
        cout << -1 << '\n';
        return 0;
    }
    vector<pair<int, int>> ab1(M1 + 1), ab2(M2 + 1);
    for (int i = 1; i <= M1; ++i) {
        cin >> ab1[i].first >> ab1[i].second;
        if (ab1[i].first > ab1[i].second) {
            swap(ab1[i].first, ab1[i].second);
        }
    }
    for (int i = 1; i <= M2; ++i) {
        cin >> ab2[i].first >> ab2[i].second;
        if (ab2[i].first > ab2[i].second) {
            swap(ab2[i].first, ab2[i].second);
        }
    }
    vector<vector<int>> G(M1 + 1, vector<int>(M2 + 1, 0));
    for (int i = 1; i <= M1; ++i) {
        for (int j = 1; j <= M2; ++j) {
            G[i][j] = -2;
            if (ab1[i].first == ab2[j].first) {
                ++G[i][j];
            }
            if (ab1[i].first == ab2[j].second) {
                ++G[i][j];
            }
            if (ab1[i].second == ab2[j].first) {
                ++G[i][j];
            }
            if (ab1[i].second == ab2[j].second) {
                ++G[i][j];
            }
        }
    }
    cout << -KM(M1, G) << '\n';

    return 0;
}