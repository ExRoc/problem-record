#include <bits/stdc++.h>
using namespace std;

struct Node {
    double x, t, s;

    Node() {}

    Node(double x, double t, double s) : x(x), t(t), s(s) {}

    double l(double tot) const { return x - (tot - t) * s; }

    double r(double tot) const { return x + (tot - t) * s; }

    bool operator<(const Node& other) const { return x < other.x; }
};

bool judge(double tot, const vector<Node>& nodes) {
    double l = nodes[0].l(tot);
    double r = nodes[0].r(tot);
    for (const Node& node : nodes) {
        l = max(l, node.l(tot));
        r = min(r, node.r(tot));
    }
    return l <= r;
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<Node> nodes(n);
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].x;
    }
    double low = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].t;
        low = max(low, nodes[i].t);
    }
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].s;
    }
    sort(nodes.begin(), nodes.end());
    double high = 2e9 + 1;
    while (high - low > 1e-7) {
        double mid = (high + low) / 2;
        if (judge(mid, nodes)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    printf("%.10lf\n", high);

    return 0;
}