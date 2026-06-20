#include <bits/stdc++.h>
using namespace std;

struct Node {
    int H, L;

    Node() {}

    Node(int H, int L) : H(H), L(L) {}

    bool operator<(const Node& other) const { return L < other.L; }
};

int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<Node> nodes(N);
    for (int i = 0; i < N; ++i) {
        cin >> nodes[i].H >> nodes[i].L;
    }
    sort(nodes.begin(), nodes.end());
    vector<int> suffixMaxH(N + 1);
    suffixMaxH[N] = 0;
    for (int i = N - 1; i >= 0; --i) {
        suffixMaxH[i] = max(suffixMaxH[i + 1], nodes[i].H);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int T;
        cin >> T;
        int idx =
            upper_bound(nodes.begin(), nodes.end(), Node(0, T)) - nodes.begin();
        cout << suffixMaxH[idx] << '\n';
    }

    return 0;
}