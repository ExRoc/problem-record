#include <bits/stdc++.h>
using namespace std;

struct Node {
    int idx, deg;

    Node() {}

    Node(int idx, int deg) : idx(idx), deg(deg) {}

    bool operator<(const Node& other) const { return deg < other.deg; }
};

struct DSU {
    int cnt_;
    vector<int> parent_;

    explicit DSU(int n) : cnt_(n), parent_(n + 1) {
        for (int i = 0; i <= n; ++i) {
            parent_[i] = i;
        }
    }

    int Find(int x) {
        return parent_[x] == x ? x : parent_[x] = Find(parent_[x]);
    }

    void Unite(int x, int y) {
        x = Find(x);
        y = Find(y);
        if (x != y) {
            --cnt_;
            parent_[y] = x;
        }
    }

    bool Same(int x, int y) { return Find(x) == Find(y); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Node> nodes(n);
    long long degSum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].deg;
        nodes[i].idx = i + 1;
        degSum += nodes[i].deg;
    }
    if (degSum != (n - 1) * 2) {
        cout << -1 << '\n';
        return 0;
    }
    sort(nodes.begin(), nodes.end());
    queue<int> que;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 1; j < nodes[i].deg; ++j) {
            int pos = que.front();
            que.pop();
            ans.push_back(make_pair(nodes[i].idx, pos));
        }
        que.push(nodes[i].idx);
    }
    while (!que.empty()) {
        ans.push_back(make_pair(nodes[n - 1].idx, que.front()));
        que.pop();
    }
    if ((int)ans.size() != n - 1) {
        cout << -1 << '\n';
        return 0;
    }
    DSU dsu(n);
    for (int i = 0; i < n - 1; ++i) {
        dsu.Unite(ans[i].first, ans[i].second);
    }
    if (dsu.cnt_ != 1) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        ++deg[ans[i].first];
        ++deg[ans[i].second];
    }
    for (int i = 0; i < n; ++i) {
        if (deg[nodes[i].idx] != nodes[i].deg) {
            cout << -1 << '\n';
            return 0;
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }

    return 0;
}