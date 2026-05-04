#include <bits/stdc++.h>
using namespace std;

class SccGraph {
   public:
    explicit SccGraph(int size)
        : n(size),
          graph(size),
          dfn(size, 0),
          low(size, 0),
          on_stack(size, false),
          timestamp(0) {}

    void AddEdge(int from, int to) { graph[from].push_back(to); }

    vector<vector<int>> Scc() {
        fill(dfn.begin(), dfn.end(), 0);
        fill(low.begin(), low.end(), 0);
        fill(on_stack.begin(), on_stack.end(), false);
        timestamp = 0;
        comps.clear();
        while (!stk.empty()) {
            stk.pop();
        }

        for (int i = 0; i < n; ++i) {
            if (dfn[i] == 0) {
                Dfs(i);
            }
        }
        return comps;
    }

   private:
    int n;
    vector<vector<int>> graph;
    vector<int> dfn;
    vector<int> low;
    vector<bool> on_stack;
    stack<int> stk;
    vector<vector<int>> comps;
    int timestamp;

    void Dfs(int u) {
        dfn[u] = low[u] = ++timestamp;
        stk.push(u);
        on_stack[u] = true;

        for (int v : graph[u]) {
            if (dfn[v] == 0) {
                Dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (on_stack[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }

        if (dfn[u] == low[u]) {
            vector<int> comp;
            int w;
            do {
                w = stk.top();
                stk.pop();
                on_stack[w] = false;
                comp.push_back(w);
            } while (w != u);
            comps.push_back(comp);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<long long> cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }
    int m;
    cin >> m;
    SccGraph scc(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        scc.AddEdge(u - 1, v - 1);
    }
    vector<vector<int>> result = scc.Scc();
    long long cnt = 1;
    long long mnCost = 0;
    const long long MOD = 1000000007;
    for (vector<int>& r : result) {
        map<long long, long long> cntMap;
        long long mn = LONG_LONG_MAX;
        for (int u : r) {
            ++cntMap[cost[u]];
            mn = min(mn, cost[u]);
        }
        mnCost += mn;
        cnt *= cntMap[mn];
        cnt %= MOD;
    }
    cout << mnCost << " " << cnt << '\n';

    return 0;
}