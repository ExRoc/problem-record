#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
struct Edge {
    int u, v, dis;
};

// 重载 Edge 的小于操作符
// 与排序相关的函数、模板类有用
// 如 sort 函数中，若 (a < b) == true 则 a 会被排在 b 前面
// 如 set、map 的 key、priority_queue 等需要进行排序的模板类，当 (a < b) == true
// 时，就会按照 a < b 的规则对 Edge 的两个对象进行排序 const Edge & 为 Edge 的
// const 引用，const 用来限制在比较时不允许修改数据，引用用于加快形参传递
bool operator<(const Edge& a, const Edge& b) { return a.dis < b.dis; }

int n, m, cnt;  // n 个节点 m 条边
int ans;
int fa[maxn];     // 并查集数组
Edge edge[maxn];  // 边数组

// 以下为并查集模板代码
void init() {
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
}

int Find(int x) { return x == fa[x] ? x : fa[x] = Find(fa[x]); }

void union_(int x, int y) { fa[Find(x)] = Find(y); }
// 以上为并查集模板代码

void kruskal() {
    init();
    // 排序时会调用上面重载的小于运算符规则
    sort(edge, edge + m);
    for (int i = 0; i < m; ++i) {
        // 如果 u 与 v 不在一个连通块内，就取这条边作为最小生成树的边，并将 u, v
        // 合并到同一个连通块
        if (Find(edge[i].u) != Find(edge[i].v)) {
            union_(edge[i].u, edge[i].v);
            ans += edge[i].dis;
            --cnt;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    cnt = n;
    for (int i = 0; i < m; ++i) {
        cin >> edge[i].u >> edge[i].v >> edge[i].dis;
    }
    kruskal();
    if (cnt == 1) {
        cout << ans << endl;
        return 0;
    }
    cout << "orz" << endl;

    return 0;
}