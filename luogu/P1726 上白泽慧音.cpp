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

    int n, m;
    cin >> n >> m;
    SccGraph scc(n);
    for (int i = 0; i < m; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        --a;
        --b;
        scc.AddEdge(a, b);
        if (t == 2) {
            scc.AddEdge(b, a);
        }
    }
    vector<vector<int>> result = scc.Scc();
    int idx = 0;
    for (int i = 0; i < (int)result.size(); ++i) {
        sort(result[i].begin(), result[i].end());
        if (result[i].size() > result[idx].size()) {
            idx = i;
        } else if (result[i].size() == result[idx].size()) {
            if (result[i][0] < result[idx][0]) {
                idx = i;
            }
        }
    }
    cout << result[idx].size() << '\n';
    for (int x : result[idx]) {
        cout << x + 1 << " ";
    }
    cout << '\n';

    return 0;
}