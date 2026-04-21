#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long LL;
const int maxn = 100000 + 100;
struct DSU {
    vector<int> parent;

    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            parent[y] = x;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    int a, b;
    int cnt = n;
    DSU dsu(n);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        if (!dsu.same(a, b)) {
            dsu.unite(a, b);
            --cnt;
        }
    }

    --cnt;
    cout << cnt << " " << (cnt * 2 + n - 1) / n << endl;
    
    return 0;
}
