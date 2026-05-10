#include <bits/stdc++.h>
using namespace std;

struct Node {
    int u, v;

    Node() {}

    Node(int u, int v) : u(u), v(v) {}

    bool operator<(const Node& other) const {
        return u == other.u ? v < other.v : u < other.u;
    }
};

bool cmp(int a, int b) { return a > b; }

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<Node> node;
    for (int i = 0; i < n; ++i) {
        int t, x;
        cin >> t >> x;
        node.push_back(Node(t + x, t - x));
    }
    sort(node.begin(), node.end());
    vector<int> dp;
    for (int i = 0; i < n; ++i) {
        int idx =
            lower_bound(dp.begin(), dp.end(), node[i].v, cmp) - dp.begin();
        if (idx == (int)dp.size()) {
            dp.push_back(node[i].v);
        } else {
            dp[idx] = node[i].v;
        }
    }
    cout << dp.size() << '\n';

    return 0;
}