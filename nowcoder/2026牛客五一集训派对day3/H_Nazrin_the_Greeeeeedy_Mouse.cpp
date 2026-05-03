#include <bits/stdc++.h>
using namespace std;

struct Node {
    int size = 0;
    int weight = 0;

    Node() {}

    Node(int size, int weight) : size(size), weight(weight) {}

    bool operator<(const Node& other) const { return false; }
};

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<Node> vct(n + 1, Node());
    for (int i = 1; i <= n; ++i) {
        cin >> vct[i].size >> vct[i].weight;
    }
    int maxSize = 200;
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(n + 1, vector<int>(maxSize + 1, 0)));
    for (int len = 1; len <= n; ++len) {
        for (int l = 1; l + len - 1 <= n; ++l) {
            int r = l + len - 1;
            for (int c = 0; c <= maxSize; ++c) {
                dp[l][r][c] = dp[l][r - 1][c];
                if (c < vct[r].size) {
                    continue;
                }
                dp[l][r][c] = max(
                    dp[l][r][c], dp[l][r - 1][c - vct[r].size] + vct[r].weight);
            }
        }
    }
    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        que.push(x);
        if ((int)que.size() > n) {
            que.pop();
        }
    }
    vector<int> sz(1, 0);
    while (!que.empty()) {
        sz.push_back(que.top());
        que.pop();
    }
    m = sz.size() - 1;
    vector<vector<int>> dpp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 0; k < i; ++k) {
                dpp[i][j] = max(dpp[i][j], dpp[k][j - 1] + dp[k + 1][i][sz[j]]);
            }
            ans = max(ans, dpp[i][j]);
        }
    }
    cout << ans << endl;

    return 0;
}