#include <bits/stdc++.h>
using namespace std;

class SccGraph {
   public:
    explicit SccGraph(int size)
        : graph(size),
          n(size),
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
        reverse(comps.begin(), comps.end());
        return comps;
    }

    vector<vector<int>> graph;

   private:
    int n;
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
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    SccGraph graph(N);
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        graph.AddEdge(A - 1, B - 1);
    }
    vector<vector<int>> comps = graph.Scc();
    vector<set<int>> compSets(comps.size());
    int degoutZeroCnt = 0;
    for (int i = 0; i < (int)comps.size(); ++i) {
        compSets[i].insert(comps[i].begin(), comps[i].end());
        int degout = 0;
        for (int j = 0; j < (int)comps[i].size(); ++j) {
            int u = comps[i][j];
            for (int k = 0; k < (int)graph.graph[u].size(); ++k) {
                int v = graph.graph[u][k];
                if (compSets[i].find(v) == compSets[i].end()) {
                    ++degout;
                }
            }
        }
        if (degout == 0) {
            ++degoutZeroCnt;
        }
    }
    if (degoutZeroCnt == 1) {
        cout << comps.back().size() << '\n';
    } else {
        cout << 0 << '\n';
    }

    return 0;
}