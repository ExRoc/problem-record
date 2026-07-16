#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int len;

    Node() {}

    Node(char ch, int len) : ch(ch), len(len) {}

    bool operator<(const Node& other) const { return false; }
};

ostream& operator<<(ostream& out, const Node& node) {
    out << "ch = " << node.ch << " len = " << node.len;
    return out;
}

long long sum(long long x) { return (x + 1) * x / 2; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    S = ' ' + S;
    for (int i = 0; i < M; ++i) {
        int L, R;
        cin >> L >> R;
        if (L > R) {
            cout << 0 << '\n';
            continue;
        }
        vector<Node> nodes;
        nodes.push_back(Node(S[L], 1));
        for (int j = L + 1; j <= R; ++j) {
            if (S[j] == nodes.back().ch) {
                ++nodes.back().len;
            } else {
                nodes.push_back(Node(S[j], 1));
            }
        }
        long long ans = 0;
        int beginIdx = 0;
        if (nodes.front().ch == '>') {
            ans += sum(nodes.front().len);
            beginIdx = 1;
        }
        int endIdx = nodes.size() - 1;
        if (nodes.back().ch == '<') {
            ans += sum(nodes.back().len);
            --endIdx;
        }
        // cout << "beginIdx: " << beginIdx << '\n';
        // cout << "endIdx: " << endIdx << '\n';
        for (int i = beginIdx; i < endIdx; i += 2) {
            // cout << "nodes[" << i << "] = " << nodes[i] << '\n';
            ans += sum(nodes[i].len) + sum(nodes[i + 1].len) -
                   min(nodes[i].len, nodes[i + 1].len);
        }
        cout << ans << '\n';
    }

    return 0;
}