#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int cnt;
    vector<int> parent;

    DSU(int n) {
        cnt = n;
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            --cnt;
            parent[y] = x;
        }
    }

    bool same(int x, int y) { return find(x) == find(y); }
};

long long fastPow(long long res, long long n, long long MOD) {
    res %= MOD;
    long long ans;
    for (ans = 1; n != 0; n >>= 1) {
        if ((n & 1) == 1) {
            ans = ans * res % MOD;
        }
        res = res * res % MOD;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    DSU dsu(n);
    int u, v;
    for (int i = 0; i < k; ++i) {
        cin >> u >> v;
        dsu.unite(u, v);
    }
    cout << fastPow(26, dsu.cnt, 998244353) << '\n';

    return 0;
}
