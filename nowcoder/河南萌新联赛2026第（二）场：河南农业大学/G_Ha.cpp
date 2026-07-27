#include <bits/stdc++.h>
using namespace std;

struct Node {
    int U, D, L, R;

    Node() {}

    Node(int _U, int _D, int _L, int _R) : U(_U), D(_D), L(_L), R(_R) {}

    bool operator<(const Node& other) const { return false; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int maxn = 2000;
    vector<vector<int>> sum(maxn + 2, vector<int>(maxn + 2, 0));
    int n;
    cin >> n;
    vector<Node> nodes(n);
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].U >> nodes[i].D >> nodes[i].L >> nodes[i].R;
        ++sum[nodes[i].U][nodes[i].L];
        --sum[nodes[i].U][nodes[i].R + 1];
        --sum[nodes[i].D + 1][nodes[i].L];
        ++sum[nodes[i].D + 1][nodes[i].R + 1];
    }
    int ansTmp = 0;
    vector<vector<int>> ans(maxn + 2, vector<int>(maxn + 2, 0));
    for (int i = 1; i <= maxn; ++i) {
        for (int j = 1; j <= maxn; ++j) {
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
            if (sum[i][j] <= 1) {
                ++ans[i][j];
            }
            if (sum[i][j] == 0) {
                ++ansTmp;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[nodes[i].D][nodes[i].R] - ans[nodes[i].U - 1][nodes[i].R] -
                    ans[nodes[i].D][nodes[i].L - 1] +
                    ans[nodes[i].U - 1][nodes[i].L - 1] + ansTmp
             << '\n';
    }

    return 0;
}