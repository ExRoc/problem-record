#include <bits/stdc++.h>
using namespace std;

struct Node {
    int pos, w;

    Node() {}

    Node(int pos, int w) : pos(pos), w(w) {}

    bool operator<(const Node& other) const { return w < other.w; }
};

void dfs(int root, vector<vector<Node>>& G, const vector<long long>& h,
         vector<long long>& ans, long long& ansTmp) {
    sort(G[root].begin(), G[root].end());
    long long lastW = 0;
    for (Node& node : G[root]) {
        ansTmp += node.w - lastW;
        dfs(node.pos, G, h, ans, ansTmp);
        lastW = node.w;
    }
    ansTmp += h[root] - lastW;
    ans[root] = ansTmp;
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<long long> h(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    vector<int> f(n + 1);
    for (int i = 2; i <= n; ++i) {
        cin >> f[i];
    }
    vector<int> w(n + 1);
    for (int i = 2; i <= n; ++i) {
        cin >> w[i];
    }
    vector<vector<Node>> G(n + 1);
    for (int i = 2; i <= n; ++i) {
        G[f[i]].push_back(Node(i, w[i]));
    }
    vector<long long> ans(n + 1);
    long long ansTmp = 0;
    dfs(1, G, h, ans, ansTmp);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << '\n';

    return 0;
}