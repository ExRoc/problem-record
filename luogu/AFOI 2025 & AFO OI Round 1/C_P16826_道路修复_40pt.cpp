#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int pos;
    long long dis;

    Edge() {}

    Edge(int _pos, long long _dis) : pos(_pos), dis(_dis) {}

    bool operator<(const Edge& other) const { return pos < other.pos; }
};

struct Query {
    int op, u, v, s;

    Query() {}

    bool operator<(const Query& other) const { return false; }
};

void solve12(int n, int q, vector<set<Edge>>& G, const vector<Query>& querys) {
    for (const Query& query : querys) {
        if (query.op == 1) {
            queue<int> que;
            vector<long long> dis(n + 1, -1);
            que.push(query.u);
            dis[query.u] = -2;
            while (!que.empty()) {
                int tmp = que.front();
                que.pop();
                for (const Edge& edge : G[tmp]) {
                    if (dis[edge.pos] == -1 && edge.pos != query.v) {
                        dis[edge.pos] = -2;
                        que.push(edge.pos);
                    }
                }
            }
            dis[query.v] = 0;
            que.push(query.v);
            while (!que.empty()) {
                int tmp = que.front();
                que.pop();
                vector<set<Edge>::iterator> its;
                for (set<Edge>::iterator it = G[tmp].begin();
                     it != G[tmp].end(); ++it) {
                    const Edge& edge = *it;
                    if (dis[edge.pos] == -1) {
                        dis[edge.pos] = dis[tmp] + edge.dis;
                        que.push(edge.pos);
                        its.push_back(it);
                    }
                }
                for (set<Edge>::iterator it : its) {
                    G[tmp].erase(it);
                }
            }
            for (int i = 1; i <= n; ++i) {
                if (i != query.v && dis[i] != -2) {
                    G[query.v].insert(Edge(i, dis[i] - dis[query.v]));
                    G[i].insert(Edge(query.v, dis[i] - dis[query.v]));
                }
            }
        } else {
            vector<long long> dis(n + 1, -1);
            dis[query.s] = 0;
            queue<int> que;
            que.push(query.s);
            long long ans = LONG_LONG_MIN;
            while (!que.empty()) {
                int tmp = que.front();
                que.pop();
                for (const Edge& edge : G[tmp]) {
                    if (dis[edge.pos] == -1) {
                        dis[edge.pos] = dis[tmp] + edge.dis;
                        que.push(edge.pos);
                        ans = max(ans, dis[edge.pos]);
                    }
                }
            }
            cout << ans << '\n';
        }
    }
}

void dfs341(int root, int fa, const vector<set<Edge>>& G,
            vector<long long>& maxDis, vector<long long>& secDis) {
    for (const Edge& edge : G[root]) {
        if (edge.pos == fa) {
            continue;
        }
        dfs341(edge.pos, root, G, maxDis, secDis);
        if (edge.dis + maxDis[edge.pos] >= maxDis[root]) {
            secDis[root] = maxDis[root];
            maxDis[root] = edge.dis + maxDis[edge.pos];
        } else {
            secDis[root] = max(secDis[root], edge.dis + maxDis[edge.pos]);
        }
    }
}

void dfs342(int root, int fa, const vector<set<Edge>>& G,
            vector<long long>& maxDis, vector<long long>& secDis,
            long long disFromFa) {
    for (const Edge& edge : G[root]) {
        if (edge.pos == fa) {
            continue;
        }
        long long disFromRoot = 0;
        if (edge.dis + maxDis[edge.pos] == maxDis[root]) {
            disFromRoot = max(disFromFa, secDis[root]) + edge.dis;
        } else {
            disFromRoot = max(disFromFa, maxDis[root]) + edge.dis;
        }
        dfs342(edge.pos, root, G, maxDis, secDis, disFromRoot);
    }
    maxDis[root] = max(maxDis[root], disFromFa);
}

void solve34(int n, int q, const vector<set<Edge>>& G,
             const vector<Query>& querys) {
    vector<long long> maxDis(n + 1, 0), secDis(n + 1, 0);
    dfs341(1, 1, G, maxDis, secDis);
    dfs342(1, 1, G, maxDis, secDis, 0);
    for (int i = 0; i < q; ++i) {
        cout << maxDis[querys[i].s] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<set<Edge>> G(n + 1);
    for (int i = 1; i < n; ++i) {
        int a, b;
        long long l;
        cin >> a >> b >> l;
        G[a].insert(Edge(b, l));
        G[b].insert(Edge(a, l));
    }
    int q;
    cin >> q;
    vector<Query> querys(q);
    for (int i = 0; i < q; ++i) {
        cin >> querys[i].op;
        if (querys[i].op == 1) {
            cin >> querys[i].u >> querys[i].v;
        } else {
            cin >> querys[i].s;
        }
    }
    if (n <= 1000 && q <= 1000) {
        solve12(n, q, G, querys);
        return 0;
    }
    bool allOp2 = true;
    for (int i = 0; i < q; ++i) {
        if (querys[i].op != 2) {
            allOp2 = false;
            break;
        }
    }
    if (allOp2) {
        solve34(n, q, G, querys);
        return 0;
    }

    return 0;
}