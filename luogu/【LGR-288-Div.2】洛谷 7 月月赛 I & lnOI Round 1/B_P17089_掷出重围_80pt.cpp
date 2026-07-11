#include <bits/stdc++.h>
using namespace std;

struct Node {
    int w, x;

    Node() : w(0), x(0) {}

    Node(int w, int x) : w(w), x(x) {}

    bool operator<(const Node& other) const { return w < other.w; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;
    vector<Node> nodes(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> nodes[i].w;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> nodes[i].x;
    }
    sort(nodes.begin(), nodes.end());
    vector<unordered_map<int, long long>> dp(s + 1);
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = s; j >= nodes[i].x; --j) {
            for (const auto& [minW, res] : dp[j - nodes[i].x]) {
                int wTmp = max(nodes[i].w, minW + 1);
                dp[j][wTmp] = max(dp[j][wTmp], res + wTmp);
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i <= s; ++i) {
        for (const auto& [minW, res] : dp[i]) {
            ans = max(ans, res);
        }
    }
    cout << ans << '\n';

    return 0;
}