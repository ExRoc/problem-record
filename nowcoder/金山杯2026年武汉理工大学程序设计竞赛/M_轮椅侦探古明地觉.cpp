#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l, r;
    long long k;

    Node() {}

    Node(int l, int r, long long k) : l(l), r(r), k(k) {}

    bool operator<(const Node& other) const { return false; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, n, m;
    cin >> N >> n >> m;
    vector<Node> nodes(n + 1);
    vector<long long> sum(N + 2, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> nodes[i].l >> nodes[i].r >> nodes[i].k;
        sum[nodes[i].l] += nodes[i].k;
        sum[nodes[i].r + 1] -= nodes[i].k;
    }
    for (int i = 1; i <= N; ++i) {
        sum[i] += sum[i - 1];
        cout << sum[i] << " ";
    }
    cout << '\n';
    vector<long long> nodesSum(n + 2, 0);
    for (int i = 1; i <= m; ++i) {
        int L, R;
        long long K;
        cin >> L >> R >> K;
        nodesSum[L] += K;
        nodesSum[R + 1] -= K;
    }
    sum.assign(N + 2, 0);
    for (int i = 1; i <= n; ++i) {
        nodesSum[i] += nodesSum[i - 1];
        nodes[i].k += nodesSum[i];
        sum[nodes[i].l] += nodes[i].k;
        sum[nodes[i].r + 1] -= nodes[i].k;
    }
    for (int i = 1; i <= N; ++i) {
        sum[i] += sum[i - 1];
        cout << sum[i] << " ";
    }
    cout << '\n';

    return 0;
}