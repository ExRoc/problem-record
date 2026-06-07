#include <bits/stdc++.h>
using namespace std;

struct Node {
    int C;
    long long V;

    Node() {}

    Node(int C, long long V) : C(C), V(V) {}

    bool operator<(const Node& other) const { return V > other.V; }
};

int main() {
    ios::sync_with_stdio(false);

    int N, K, M;
    cin >> N >> K >> M;
    vector<Node> nodes(N);
    for (int i = 0; i < N; ++i) {
        cin >> nodes[i].C >> nodes[i].V;
    }
    vector<bool> vis(N, false);
    sort(nodes.begin(), nodes.end());
    set<int> Cs;
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        if (Cs.find(nodes[i].C) == Cs.end()) {
            Cs.insert(nodes[i].C);
            ans += nodes[i].V;
            vis[i] = true;
            if ((int)Cs.size() == M) {
                break;
            }
        }
    }
    int cnt = K - M;
    for (int i = 0; i < N; ++i) {
        if (vis[i]) {
            continue;
        }
        if (cnt > 0) {
            ans += nodes[i].V;
            --cnt;
        } else {
            break;
        }
    }
    cout << ans << '\n';

    return 0;
}