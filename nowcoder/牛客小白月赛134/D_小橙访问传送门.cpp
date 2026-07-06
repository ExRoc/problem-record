#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long x;
    int color;

    Node() {}

    Node(long long x, int color) : x(x), color(color) {}

    bool operator<(const Node& other) const { return x < other.x; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<Node> nodes(n + m);
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].x;
        nodes[i].color = 0;
    }
    for (int i = 0; i < m; ++i) {
        cin >> nodes[i + n].x;
        nodes[i + n].color = 1;
    }
    sort(nodes.begin(), nodes.end());
    long long ans1 = LONG_LONG_MAX;
    long long ans2 = LONG_LONG_MAX;
    long long ans3 = LONG_LONG_MAX;
    for (int i = 0; i < n + m; ++i) {
        if (nodes[i].color == 0) {
            ans1 = min(ans1, abs(nodes[i].x));
        } else {
            ans2 = min(ans2, abs(nodes[i].x));
        }
        if (i > 0 && nodes[i].color != nodes[i - 1].color) {
            ans3 = min(ans3, nodes[i].x - nodes[i - 1].x);
        }
    }
    cout << min({ans1 + ans3 + ans2, ans1 + ans3 + ans3 + ans1,
                 ans2 + ans3 + ans3 + ans2})
         << '\n';

    return 0;
}