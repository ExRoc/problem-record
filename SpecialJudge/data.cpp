#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

// 所有随机范围均使用const定义，可直接修改这里调整生成规模
const int MAX_T = 3;           // 测试用例数量上限
const int MAX_N = 4;           // n最大，如需大测试可改为100000
const int MAX_M = 2;           // m最大
const int MAX_K = 3;           // k上限，题目k ≤ 100
const long long MAX_X = 10LL;  // x上限1e9

mt19937 rng;

// [L, R] 闭区间随机int
inline int rand_int(int L, int R) {
    uniform_int_distribution<int> dist(L, R);
    return dist(rng);
}
// [L, R] 闭区间随机long long
inline long long rand_ll(long long L, long long R) {
    uniform_int_distribution<long long> dist(L, R);
    return dist(rng);
}

int main() {
    // 使用系统当前时间（毫秒级时间戳）作为随机种子
    auto seed = chrono::system_clock::now().time_since_epoch().count();
    rng.seed((unsigned long long)seed);

    int t = rand_int(1, MAX_T);
    cout << t << '\n';

    for (int cas = 0; cas < t; ++cas) {
        int n = rand_int(2, MAX_N);
        int k = rand_int(1, MAX_K);
        int max_possible_m = min(MAX_M, n * (n - 1) / 2);
        int m = rand_int(1, max_possible_m);

        cout << n << " " << m << " " << k << "\n";

        // 给每个节点分配拓扑编号，保证生成出来一定是DAG
        vector<int> topo_id(n + 1);
        for (int i = 1; i <= n; ++i) topo_id[i] = i;
        shuffle(topo_id.begin() + 1, topo_id.end(), rng);

        // 生成m条DAG边 u→v：必须 topo_id[u] < topo_id[v]，保证无环
        for (int i = 0; i < m; ++i) {
            int u, v;
            do {
                u = rand_int(1, n);
                v = rand_int(1, n);
            } while (topo_id[u] >= topo_id[v]);
            cout << u << " " << v << "\n";
        }

        // 生成k条缆车 a→b；题目约束：仅雪道b可以到达a → topo_id[b] < topo_id[a]
        vector<pair<int, int>> lifts;
        for (int i = 0; i < k; ++i) {
            int a, b;
            do {
                a = rand_int(1, n);
                b = rand_int(1, n);
            } while (topo_id[b] >= topo_id[a]);
            lifts.emplace_back(a, b);
            cout << a << " " << b << "\n";
        }

        // x随机
        long long x = rand_ll(1LL, MAX_X);

        // y: 题目保证y可以到达至少一条缆车起点。
        // 随机选一条缆车的起点pick_a，y必须拓扑序<=pick_a，保证y可达pick_a
        int pick_idx = rand_int(0, k - 1);
        int pick_a = lifts[pick_idx].first;
        int y;
        do {
            y = rand_int(1, n);
        } while (topo_id[y] > topo_id[pick_a]);

        cout << x << " " << y << "\n";
    }
    return 0;
}
