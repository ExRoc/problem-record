#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 26;
int n, ans;
string s, t;
bool vis[maxn];
int G[maxn][maxn];
int degOut[maxn], fa[maxn], cnt[maxn], degIn[maxn];

void build() {
    memset(degOut, 0, sizeof(degOut));
    memset(degIn, 0, sizeof(degIn));
    for (int i = 0; i < n; ++i) {
        fa[i] = i;
        cnt[i] = 1;
        for (int j = 0; j < n; ++j) {
            if (G[i][j]) {
                ++degOut[i];
                ++degIn[j];
            }
        }
    }
}

void clearSelfLoop() {
    for (int i = 0; i < n; ++i) {
        if (G[i][i] == 1) {
            --degOut[i];
            --degIn[i];
        }
    }
}

int findF(int x) {
    return fa[x] == x ? x : fa[x] = findF(fa[x]);
}

void union_(int x, int y) {
    x = findF(x);
    y = findF(y);
    if (x != y) {
        fa[x] = y;
        cnt[y] += cnt[x];
        degOut[y] += degOut[x];
    }
}

void connect() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (G[i][j] == 1) {
                union_(i, j);
            }
        }
    }
}

int id(char ch) {
    return ch - 'a';
}

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);

    cin >> n >> s >> t;
    n = 26;
    for (int i = 0; i < s.length(); ++i) {
        G[id(s[i])][id(t[i])] = 1;
    }
    build();
    for (int i = 0; i < n; ++i) {
        if (degOut[i] > 1) {
            cout << -1 << endl;
            return 0;
        }
    }
    clearSelfLoop();
    connect();
    bool hasLoop = false;
    for (int i = 0; i < n; ++i) {
        int f = findF(i);
        if (degOut[f] == cnt[f]) {
            bool allInOne = true;
            for (int j = 0; j < n; ++j) {
                if (findF(j) == f && degIn[j] != 1) {
                    allInOne = false;
                    break;
                }
            }
            if (allInOne) {
                hasLoop = true;
                break;
            }
        }
    }
    build();
    bool zeroIn = false;
    for (int i = 0; i < n; ++i) {
        if (degIn[i] == 0) {
            zeroIn = true;
            break;
        }
    }
    if (hasLoop && !zeroIn) {
        cout << -1 << endl;
        return 0;
    }
    build();
    clearSelfLoop();
    connect();
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i) {
        int f = findF(i);
        if (vis[f]) {
            continue;
        }
        vis[f] = true;
        ans += degOut[f];
        bool allInOne = true;
        for (int j = 0; j < n; ++j) {
            if (findF(j) == f && degIn[j] != 1) {
                allInOne = false;
                break;
            }
        }
        if (allInOne) {
            ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}
