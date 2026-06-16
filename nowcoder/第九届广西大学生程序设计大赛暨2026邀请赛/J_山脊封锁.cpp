#include <bits/stdc++.h>
using namespace std;

struct Node {
    int idx;
    long long a, b;

    Node() {}

    Node(int idx, long long a, long long b) : idx(idx), a(a), b(b) {}

    bool operator<(const Node& other) const { return a < other.a; }
};

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<Node> nodes(N);
        for (int i = 0; i < N; ++i) {
            nodes[i].idx = i;
            cin >> nodes[i].a;
        }
        long long mxB = LONG_LONG_MIN;
        long long mnB = LONG_LONG_MAX;
        long long ans = 0;
        for (int i = 0; i < N; ++i) {
            cin >> nodes[i].b;
            mxB = max(mxB, nodes[i].b);
            mnB = min(mnB, nodes[i].b);
            ans += abs(nodes[i].b - nodes[i].a);
        }
        sort(nodes.begin(), nodes.end());
        if (nodes.front().a > mnB || nodes.back().a < mxB) {
            cout << -1 << '\n';
            continue;
        }
        if (N == 1) {
            cout << 0 << '\n';
            continue;
        }
        if (N == 2) {
            if (nodes[0].b <= nodes[1].b) {
                cout << ans << '\n';
            } else {
                cout << -1 << '\n';
            }
            continue;
        }
        if (mxB != nodes.front().b || mnB != nodes.back().b) {
            cout << ans << '\n';
            continue;
        }
        long long tmp = ans;
        ans = LONG_LONG_MAX;
        for (int i = 1; i < N - 1; ++i) {
            if (nodes[i].a <= mnB || nodes[i].a >= mxB) {
                ans = min(ans, tmp);
                continue;
            }
            ans = min({ans, tmp + (min(nodes[i].a, nodes[i].b) - mnB) * 2,
                       tmp + (mxB - max(nodes[i].a, nodes[i].b)) * 2});
        }
        cout << ans << '\n';
    }

    return 0;
}