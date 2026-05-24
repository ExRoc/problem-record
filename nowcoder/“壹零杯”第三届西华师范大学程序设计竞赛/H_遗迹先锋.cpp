#include <bits/stdc++.h>
using namespace std;

struct Node {
    string Name;
    int S, A, C;

    Node() {}

    Node(string Name, int S, int A, int C) : Name(Name), S(S), A(A), C(C) {}

    bool operator<(const Node& other) const {
        return S == other.S ? (A == other.A ? Name < other.Name : A > other.A)
                            : S > other.S;
    }
};

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<Node> nodes(N);
        for (int i = 0; i < N; ++i) {
            cin >> nodes[i].Name >> nodes[i].S >> nodes[i].A >> nodes[i].C;
        }
        sort(nodes.begin(), nodes.end());
        vector<int> Cs;
        for (int i = 0; i < K; ++i) {
            Cs.push_back(nodes[i].C);
        }
        sort(Cs.begin(), Cs.end());
        vector<int> Es(K);
        for (int i = 0; i < K; ++i) {
            cin >> Es[i];
        }
        sort(Es.begin(), Es.end());
        long long ans = 0;
        for (int i = 0; i < K; ++i) {
            ans += 1LL * Cs[i] * Es[i];
        }
        cout << ans << '\n';
    }

    return 0;
}