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
    SccGraph scc(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        scc.AddEdge(i, x - 1);
    }
    vector<vector<int>> result = scc.Scc();
    int ans = INT_MAX;
    for (vector<int>& r : result) {
        if ((int)r.size() == 1) {
            continue;
        }
        ans = min(ans, (int)r.size());
    }
    cout << ans << '\n';

    return 0;
}