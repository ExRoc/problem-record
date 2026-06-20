#include <bits/stdc++.h>
using namespace std;

struct Node {
    int L, R;

    Node() {}

    Node(int L, int R) : L(L), R(R) {}

    bool operator<(const Node& other) const { return R < other.R; }
};

bool judge(int minDis, const vector<Node>& nodes, int N, int K) {
    int last = nodes[0].R;
    --K;
    for (int i = 1; i < N; ++i) {
        if (nodes[i].L - last >= minDis) {
            --K;
            last = nodes[i].R;
        }
    }
    return K <= 0;
}

int main() {
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<Node> nodes(N);
    int minL = INT_MAX;
    int maxR = INT_MIN;
    for (int i = 0; i < N; ++i) {
        cin >> nodes[i].L >> nodes[i].R;
        minL = min(minL, nodes[i].L);
        maxR = max(maxR, nodes[i].R);
    }
    sort(nodes.begin(), nodes.end());
    int low = 0;
    int high = maxR - minL + 1;
    while (high - low > 1) {
        int mid = (high + low) >> 1;
        if (judge(mid, nodes, N, K)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    cout << (low == 0 ? -1 : low) << '\n';

    return 0;
}