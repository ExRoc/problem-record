#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 300000 + 100;
struct Node {
    int idx;
    vector<int> vct;
    Node() {}
    Node(int idx) : idx(idx) {}
};

int n, idx, x, y;
int ridx[maxn];
map<int, Node> G[maxn];
map<int, Node>::iterator it;

void dfs(int root) {
    for (map<int, Node>::iterator it = G[root].begin(); it != G[root].end();
         ++it) {
        sort((it->second).vct.begin(), (it->second).vct.end());
        for (int x : (it->second).vct) {
            cout << x << " ";
        }
        dfs((it->second).idx);
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        int ii = ridx[x];
        it = G[ii].find(y);
        if (it == G[ii].end()) {
            G[ii][y] = Node(++idx);
            it = G[ii].find(y);
        }
        (it->second).vct.push_back(i);
        ridx[i] = (it->second).idx;
    }
    dfs(0);

    return 0;
}
