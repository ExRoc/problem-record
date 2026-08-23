/*
暴力对拍程序
适用限制：n,m,k <=10，测试组数 t<=3
输入格式与原题完全一致，可以直接和数据生成器、倍增版本对拍
实现思路：
dp_max[c][u]：已经使用 c 次缆车，当前处于结点 u，能达到的最大累计时间
snow_dist[s][t]：仅走雪道，s到t的最长路径边数；不可达记为 -INF
ld[s]：仅走雪道，从s出发可以走的最大步数
best[c]：使用至多 c 次缆车时，能取得的全局最大总时间
从小到大枚举缆车次数，找到最小 c，满足 best[c] >= x
全部使用long long，规避溢出，算法逻辑直白，无倍增、无矩阵，降低逻辑错误点
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 12;
const int MAXK = 12;
const int MAXCNT = 200;  // 小规模下足够的最大缆车次数
const long long INF = -1000000000000000000LL;

struct Edge {
    int v, nxt;
} es[200];
int head[MAXN], idx;

struct Lift {
    int sd, kfz;
} lc[MAXK];

long long snow_dist[MAXN][MAXN];
long long ld[MAXN];
bool vis[MAXN];

inline void add(int u, int v) {
    es[++idx].v = v;
    es[idx].nxt = head[u];
    head[u] = idx;
}

// DFS求从s出发，所有点的最长雪道路径，DAG无环，n<=10安全
void dfs_snow(int s, int u, long long cur_len) {
    if (cur_len > snow_dist[s][u]) {
        snow_dist[s][u] = cur_len;
    }
    vis[u] = true;
    for (int eid = head[u]; eid; eid = es[eid].nxt) {
        int v = es[eid].v;
        if (!vis[v]) {
            dfs_snow(s, v, cur_len + 1);
        }
    }
    vis[u] = false;
}

int main() {
    int t;
    while (scanf("%d", &t) == 1) {
        while (t--) {
            int n, m, k;
            scanf("%d%d%d", &n, &m, &k);

            // 初始化邻接表
            idx = 0;
            memset(head, 0, sizeof head);
            for (int i = 1; i <= m; ++i) {
                int u, v;
                scanf("%d%d", &u, &v);
                add(u, v);
            }

            for (int i = 1; i <= k; ++i) {
                scanf("%d%d", &lc[i].sd, &lc[i].kfz);
            }

            long long x;
            int y;
            scanf("%lld%d", &x, &y);

            // --------预处理雪道最长路径--------
            for (int s = 1; s <= n; ++s) {
                for (int t = 1; t <= n; ++t) snow_dist[s][t] = INF;
                memset(vis, 0, sizeof vis);
                dfs_snow(s, s, 0LL);
                // ld[s]: s出发只走雪道的最大步数
                ld[s] = 0;
                for (int t = 1; t <= n; ++t) {
                    if (snow_dist[s][t] > ld[s]) {
                        ld[s] = snow_dist[s][t];
                    }
                }
            }

            // dp_max[c][u]: c次缆车，当前在u，最大累计时间
            long long dp_max[MAXCNT + 5][MAXN];
            long long best[MAXCNT + 5];
            for (int c = 0; c <= MAXCNT; ++c) {
                best[c] = INF;
                for (int u = 1; u <= n; ++u) {
                    dp_max[c][u] = INF;
                }
            }
            dp_max[0][y] = 0;

            for (int cnt = 0; cnt < MAXCNT; ++cnt) {
                // 遍历所有结点状态
                for (int u = 1; u <= n; ++u) {
                    if (dp_max[cnt][u] == INF) continue;
                    // 选择1：直接终止，不再坐缆车，总时间=已用时间 +
                    // u出发全部雪道
                    long long total_stop = dp_max[cnt][u] + ld[u];
                    if (total_stop > best[cnt]) {
                        best[cnt] = total_stop;
                    }
                    // 选择2：尝试坐任意一条缆车 j
                    for (int j = 1; j <= k; ++j) {
                        int a = lc[j].sd;
                        int b = lc[j].kfz;
                        long long d = snow_dist[u][a];
                        if (d == INF) continue;  // u雪道到不了缆车起点a，不能坐
                        long long new_time = dp_max[cnt][u] + d + 1;
                        if (new_time > dp_max[cnt + 1][b]) {
                            dp_max[cnt + 1][b] = new_time;
                        }
                    }
                }
            }

            // 寻找最小缆车次数
            int ans = -1;
            for (int c = 0; c <= MAXCNT; ++c) {
                if (best[c] >= x) {
                    ans = c;
                    break;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
