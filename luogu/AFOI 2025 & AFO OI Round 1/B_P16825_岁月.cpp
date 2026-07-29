#include <bits/stdc++.h>
using namespace std;

class CutVertexFinder {
   public:
    CutVertexFinder(int n)
        : n_(n),
          adj_(n),
          dfn_(n, 0),
          low_(n, 0),
          is_cut_(n, false),
          timer_(0),
          edge_cnt_(0) {}

    void AddEdge(int u, int v) {
        if (u < 0 || u >= n_ || v < 0 || v >= n_) {
            return;
        }
        ++edge_cnt_;
        adj_[u].push_back({v, edge_cnt_});
        adj_[v].push_back({u, edge_cnt_});
    }

    vector<int> Find() {
        fill(dfn_.begin(), dfn_.end(), 0);
        fill(low_.begin(), low_.end(), 0);
        fill(is_cut_.begin(), is_cut_.end(), false);
        timer_ = 0;

        for (int i = 0; i < n_; ++i) {
            if (!dfn_[i]) {
                dfs(i, -1);
            }
        }

        vector<int> result;
        for (int i = 0; i < n_; ++i) {
            if (is_cut_[i]) {
                result.push_back(i);
            }
        }
        return result;
    }

   private:
    void dfs(int u, int parent_edge) {
        dfn_[u] = low_[u] = ++timer_;
        int child = 0;

        for (auto& e : adj_[u]) {
            int v = e.first;
            int id = e.second;

            if (id == parent_edge) {
                continue;
            }

            if (!dfn_[v]) {
                ++child;
                dfs(v, id);
                low_[u] = min(low_[u], low_[v]);

                if (parent_edge == -1 && child > 1) {
                    is_cut_[u] = true;
                }
                if (parent_edge != -1 && low_[v] >= dfn_[u]) {
                    is_cut_[u] = true;
                }
            } else {
                low_[u] = min(low_[u], dfn_[v]);
            }
        }
    }

    int n_;
    vector<vector<pair<int, int>>> adj_;
    vector<int> dfn_, low_;
    vector<bool> is_cut_;
    int timer_;
    int edge_cnt_;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        CutVertexFinder cut(n + 1);
        for (int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            cut.AddEdge(u, v);
        }
        vector<int> cutVertiexes = cut.Find();
        vector<bool> isCut(n + 1, false);
        for (int i = 0; i < cutVertiexes.size(); ++i) {
            isCut[cutVertiexes[i]] = true;
        }
        int ans = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            if (!isCut[i]) {
                ans = min(ans, a[i]);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}