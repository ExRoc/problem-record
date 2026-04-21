#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 300000 + 100;
struct Edge {
    int u, v, dis;
};

bool operator<(const Edge& a, const Edge& b) { return a.dis < b.dis; }

struct Node {
    int x, y, z;
    int idx;
};

bool cmpX(const Node& a, const Node& b) { return a.x < b.x; }

bool cmpY(const Node& a, const Node& b) { return a.y < b.y; }

bool cmpZ(const Node& a, const Node& b) { return a.z < b.z; }

int n, ecnt;
LL ans;
int fa[maxn];
Node node[maxn];
Edge edge[maxn];

void init() {
    for (int i = 0; i < n; ++i) {
        fa[i] = i;
    }
}

int findF(int x) { return x == fa[x] ? x : fa[x] = findF(fa[x]); }

void union_(int x, int y) { fa[findF(x)] = findF(y); }

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> node[i].x >> node[i].y >> node[i].z;
        node[i].idx = i;
    }
    sort(node, node + n, cmpX);
    for (int i = 1; i < n; ++i) {
        edge[ecnt++] = {node[i].idx, node[i - 1].idx,
                        node[i].x - node[i - 1].x};
    }
    sort(node, node + n, cmpY);
    for (int i = 1; i < n; ++i) {
        edge[ecnt++] = {node[i].idx, node[i - 1].idx,
                        node[i].y - node[i - 1].y};
    }
    sort(node, node + n, cmpZ);
    for (int i = 1; i < n; ++i) {
        edge[ecnt++] = {node[i].idx, node[i - 1].idx,
                        node[i].z - node[i - 1].z};
    }
    sort(edge, edge + ecnt);
    init();
    for (int i = 0; i < ecnt; ++i) {
        if (findF(edge[i].u) != findF(edge[i].v)) {
            union_(edge[i].u, edge[i].v);
            ans += edge[i].dis;
        }
    }
    cout << ans << endl;

    return 0;
}