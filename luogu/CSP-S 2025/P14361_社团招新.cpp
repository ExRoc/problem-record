#include <bits/stdc++.h>
using namespace std;

struct OneNum {
    int idx, x;

    OneNum() {}

    OneNum(int idx, int x) : idx(idx), x(x) {}

    bool operator<(const OneNum& other) const { return x > other.x; }
};

struct Node {
    OneNum a[3];

    Node() {}

    Node(int _a, int b, int c) {
        a[0] = OneNum(0, _a);
        a[1] = OneNum(1, b);
        a[2] = OneNum(2, c);
    }

    bool operator<(const Node& other) const {
        return a[0].x - a[1].x > other.a[0].x - other.a[1].x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long ans = 0;
        vector<vector<Node>> vct(3);
        for (int i = 0; i < n; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            int man = 0;
            if (a >= b && a >= c) {
                man = 0;
                ans += a;
            } else if (b >= a && b >= c) {
                man = 1;
                ans += b;
            } else {
                man = 2;
                ans += c;
            }
            Node node(a, b, c);
            sort(node.a, node.a + 3);
            vct[man].push_back(node);
        }
        int idx = 0;
        for (int i = 0; i < 3; ++i) {
            if (vct[i].size() > n / 2) {
                idx = i;
            }
            sort(vct[i].begin(), vct[i].end());
        }
        for (int i = vct[idx].size() - 1; i >= n / 2; --i) {
            ans += vct[idx][i].a[1].x - vct[idx][i].a[0].x;
        }
        cout << ans << '\n';
    }

    return 0;
}