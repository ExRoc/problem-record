#include <bits/stdc++.h>
using namespace std;

struct Node {
    int pos;
    long long dis;

    Node() {}

    Node(int pos, long long dis) : pos(pos), dis(dis) {}

    bool operator<(const Node& other) const { return dis < other.dis; }
};

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
        reverse(comps.begin(), comps.end());
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

    int n, q;
    cin >> n >> q;
    vector<vector<Node>> G(n + 1);
    SccGraph scc(n + 1);
    for (int i = 0; i < q; ++i) {
        int a, c;
        long long b;
        cin >> a >> b >> c;
        G[a].push_back(Node(c, b));
        scc.AddEdge(a, c);
    }
    vector<long long> ans(n + 1, 0);
    vector<vector<int>> sccResults = scc.Scc();
    for (vector<int>& sccRes : sccResults) {
        bool flag = false;
        set<int> resSet(sccRes.begin(), sccRes.end());
        for (int tmp : sccRes) {
            for (Node& node : G[tmp]) {
                if (resSet.find(node.pos) != resSet.end() && node.dis > 1) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        if (flag) {
            for (int tmp : sccRes) {
                ans[tmp] = -1;
            }
        }
    }
    if (ans[1] != -1) {
        vector<int> id(n + 1);
        for (int i = 0; i < (int)sccResults.size(); ++i) {
            for (int pos : sccResults[i]) {
                id[pos] = i;
            }
        }
        vector<vector<Node>> GG(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (ans[i] == -1) {
                continue;
            }
            for (Node& node : G[i]) {
                if (ans[node.pos] == -1) {
                    continue;
                }
                if (id[i] != id[node.pos]) {
                    GG[id[i]].push_back(Node(id[node.pos], node.dis));
                }
            }
        }
        priority_queue<Node> que;
        vector<long long> dis(n + 1, 0);
        que.push(Node(id[1], 1));
        dis[id[1]] = 1;
        while (!que.empty()) {
            Node tmp = que.top();
            que.pop();
            tmp.dis = max(tmp.dis, dis[tmp.pos]);
            for (Node& node : GG[tmp.pos]) {
                long long disTmp = tmp.dis * node.dis;
                if (disTmp > dis[node.pos]) {
                    dis[node.pos] = disTmp;
                    que.push(Node(node.pos, disTmp));
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (dis[id[i]] != 0) {
                ans[i] = dis[id[i]];
            }
        }
    }
    queue<int> que;
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == -1) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int tmp = que.front();
        que.pop();
        for (Node& node : G[tmp]) {
            if (ans[node.pos] != -1) {
                ans[node.pos] = -1;
                que.push(node.pos);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << '\n';

    return 0;
}