#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
const int Log = 20;
int n, u, v, idCnt;
LL ans;
bool flag;
vector<int> G[maxn];
int st[maxn][Log];
int id[maxn], degcnt[maxn], deg[maxn];
LL son[maxn];

void dfs(int root, int fa) {
    id[root] = ++idCnt;
    st[root][0] = fa;
    for (int j = 1; j < Log; ++j) {
        st[root][j] = st[st[root][j - 1]][j - 1];
    }
    for (int pos : G[root]) {
        if (pos != fa) {
            dfs(pos, root);
            son[root] += son[pos];
        }
    }
    ++son[root];
}

int lcaPre(int x, int y) {
    if (x == y) {
        return x;
    }
    if (id[x] > id[y]) {
        swap(x, y);
    }
    for (int i = Log - 1; i >= 0; --i) {
        if (id[st[y][i]] > id[x]) {
            y = st[y][i];
        }
    }
    return y;
}

int lca(int x, int y) {
    return st[lcaPre(x, y)][0];
}

LL solve(int x) {
    int lcauPre = lcaPre(u, x);
    int lcau = st[lcauPre][0];
    int lcau0Pre = lcaPre(u, 0);
    if (lcau == x) {
        // cout << "match 1" << endl;
        return 0;
    }
    if (lcau == u) {
        LL ans =
            (son[u] - son[x]) * (v == -1 ? son[0] - son[lcau0Pre] : son[v]);
        u = x;
        // cout << "match 2" << endl;
        return ans;
    }
    int lcauxPre0Pre = lcaPre(lcauPre, 0);
    if (lca(lcauxPre0Pre, x) == lcauxPre0Pre &&
        lcauxPre0Pre == lca(lcauxPre0Pre, u)) {
        flag = false;
        // cout << "match 3" << endl;
        return son[u] * (v == -1 ? (son[0] - son[lcauxPre0Pre]) : son[v]);
    }
    if (v == -1) {
        LL ans = son[u] * (son[0] - son[x] - son[lcau0Pre]);
        v = x;
        // cout << "match 4" << endl;
        return ans;
    }
    int lcavPre = lcaPre(v, x);
    int lcav = st[lcavPre][0];
    if (lcav == 0) {
        flag = false;
        // cout << "match 5" << endl;
        return son[u] * son[v];
    }
    if (lcav == x) {
        // cout << "match 6" << endl;
        return 0;
    }
    if (lcav == v) {
        LL ans = (son[v] - son[x]) * son[u];
        v = x;
        // cout << "match 7" << endl;
        return ans;
    }
    flag = false;
    // cout << "match 8" << endl;
    return son[u] * son[v];
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }
    for (int i = 0; i < n; ++i) {
        ++degcnt[deg[i]];
    }
    dfs(0, 0);
    ans = 1;
    int tmp = lcaPre(0, 1);
    LL sumTmp = 0;
    for (int pos : G[0]) {
        if (pos != tmp) {
            ans += son[pos];
            ans += sumTmp * son[pos];
            sumTmp += son[pos];
        } else {
            ans += son[pos] - son[1];
            ans += sumTmp * (son[pos] - son[1]);
            sumTmp += son[pos] - son[1];
        }
    }
    // cout << "ans = " << ans << endl;
    // ans += 2 * (son[1]) * (son[0] - son[tmp]);
    u = 1;
    v = -1;
    flag = true;
    for (int i = 2; i < n; ++i) {
        LL tmp = solve(i);
        // cout << "i = " << i << " tmp = " << tmp << " u = " << u << " v = " <<
        // v
        //      << endl;
        ans += tmp * i;
        if (!flag) {
            break;
        }
    }
    if (degcnt[1] == 2 && degcnt[2] == n - 2) {
        ans += n;
    }
    cout << ans << endl;

    return 0;
}
