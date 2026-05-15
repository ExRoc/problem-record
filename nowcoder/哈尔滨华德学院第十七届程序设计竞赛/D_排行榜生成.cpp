#include <bits/stdc++.h>
using namespace std;

struct Node {
    string sid;
    int cnt, sum;

    Node() {}

    Node(string& sid, int cnt, int sum) : sid(sid), cnt(cnt), sum(sum) {}

    bool operator<(const Node& other) const {
        return cnt == other.cnt
                   ? (sum == other.sum ? sid < other.sid : sum < other.sum)
                   : cnt > other.cnt;
    }

    bool operator==(const Node& other) {
        return cnt == other.cnt && sum == other.sum;
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<Node> nodes(n);
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].sid;
        nodes[i].sum = nodes[i].cnt = 0;
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            if (x > 0) {
                ++nodes[i].cnt;
                nodes[i].sum += x;
            }
        }
    }
    sort(nodes.begin(), nodes.end());
    int idx = 1;
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            if (!(nodes[i] == nodes[i - 1])) {
                idx = i + 1;
            }
        }
        cout << idx << " " << nodes[i].sid << " " << nodes[i].cnt << " "
             << nodes[i].sum << '\n';
    }

    return 0;
}