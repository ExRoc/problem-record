#include <bits/stdc++.h>
using namespace std;

struct Node {
    int num, cnt;

    Node() {}

    void cal() {
        int tmp = num;
        cnt = 0;
        while ((tmp & 1) == 0) {
            ++cnt;
            tmp >>= 1;
        }
    }

    Node(int num, int cnt) : num(num) { cal(); }

    bool operator<(const Node& other) const { return cnt > other.cnt; }
};

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<Node> nodes(n);
        for (int i = 0; i < n; ++i) {
            cin >> nodes[i].num;
            nodes[i].cal();
        }
        sort(nodes.begin(), nodes.end());
        for (int i = 0; i < k; ++i) {
            cout << nodes[i].num << " ";
        }
        cout << '\n';
    }

    return 0;
}