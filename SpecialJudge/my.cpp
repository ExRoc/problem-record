#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 100005
#define M 100005
#define K 105

int n, m, k;
struct edge {
    int v, nxt;
    edge() {}
    edge(int v, int nxt) : v(v), nxt(nxt) {}
} es[M];
int idx, head[N];
struct sdkfz {
    int sd, kfz;
} lc[N];
int fr[N];
long long ld[N], lsd[N][K];
long long dis[K + 2][K + 2][31];
long long ard[K + 2], ardd[K + 2];

inline void add(int u, int v) {
    es[++idx] = edge(v, head[u]);
    head[u] = idx;
}

void fld(int u) {
    if (ld[u] >= 0) return;
    if (fr[u]) lsd[u][fr[u]] = 0;
    if (head[u])
        for (int eid = head[u]; eid; eid = es[eid].nxt) {
            int v = es[eid].v;
            fld(v);
            ld[u] = max(ld[u], ld[v] + 1);
            for (int i = 1; i <= k; ++i)
                lsd[u][i] = max(lsd[u][i], lsd[v][i] + 1);
        }
    else
        ld[u] = 0;
}

signed main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &m, &k);
        idx = 0;
        for (int i = 1; i <= n; ++i) head[i] = 0, fr[i] = 0;
        for (int i = 1; i <= m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
        }
        for (int i = 1; i <= k; ++i)
            scanf("%d%d", &lc[i].sd, &lc[i].kfz), fr[lc[i].sd] = i;
        int x, y;
        scanf("%d%d", &x, &y);
        for (int i = 1; i <= n; ++i) {
            ld[i] = -4e18;
            for (int j = 1; j <= k; ++j) lsd[i][j] = -4e18;
        }
        for (int i = 1; i <= n; ++i) fld(i);
        for (int i = 1; i <= k + 2; ++i)
            for (int j = 1; j <= k + 2; ++j)
                for (int t = 0; t <= 30; ++t) dis[i][j][t] = -4e18;
        for (int i = 1; i <= k; ++i)
            for (int j = 1; j <= k; ++j) dis[i][j][0] = lsd[lc[i].kfz][j] + 1;
        for (int i = 1; i <= k; ++i)
            dis[k + 1][i][0] = lsd[y][i] + 1, dis[i][k + 2][0] = ld[lc[i].kfz];
        dis[k + 1][k + 2][0] = ld[y];
        for (int t = 1; t <= 30; ++t)
            for (int r = 1; r <= k + 2; ++r)
                for (int i = 1; i <= k + 2; ++i)
                    for (int j = 1; j <= k + 2; ++j)
                        if (dis[i][r][t - 1] >= 0 && dis[r][j][t - 1] >= 0)
                            dis[i][j][t] =
                                max(dis[i][j][t],
                                    dis[i][r][t - 1] + dis[r][j][t - 1]);
        for (int i = 1; i <= k + 2; ++i) ard[i] = -4e18;
        ard[k + 1] = 0;
        long long ald = 0, ans = 4e18;
        for (int t = 30; t >= 0; --t) {
            long long maxs = -4e18;
            for (int i = 1; i <= k + 2; ++i)
                if (ard[i] >= 0 && dis[i][k + 2][t] >= 0)
                    maxs = max(maxs, ard[i] + dis[i][k + 2][t]);
            if (maxs >= x)
                ans = min(ans, ald + (1 << t));
            else {
                ald += (1 << t);
                for (int i = 1; i <= k + 2; ++i)
                    ardd[i] = ard[i], ard[i] = -4e18;
                for (int i = 1; i <= k + 2; ++i)
                    for (int j = 1; j <= k + 2; ++j)
                        if (ardd[i] >= 0 && dis[i][j][t] >= 0)
                            ard[j] = max(ard[j], ardd[i] + dis[i][j][t]);
            }
        }
        if (ans < 1e18)
            printf("%lld\n", ans - 1);
        else
            puts("-1");
    }
    return 0;
}