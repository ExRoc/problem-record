#include <bits/stdc++.h>
using namespace std;

struct Node {
    int pos, deg;

    Node() {}

    Node(int pos, int deg) : pos(pos), deg(deg) {}

    bool operator<(const Node& other) const { return deg > other.deg; }
};

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, L;
        cin >> n >> L;
        vector<Node> nodes(n);
        for (int i = 0; i < n; ++i) {
            cin >> nodes[i].deg;
            nodes[i].pos = i + 1;
        }
        sort(nodes.begin(), nodes.end());
        vector<pair<int, int>> ans;
        bool flag = true;
        for (int i = 1; i < n - L; ++i) {
            ans.push_back(make_pair(nodes[i - 1].pos, nodes[i].pos));
            --nodes[i - 1].deg;
            --nodes[i].deg;
            if (nodes[i].deg < 0) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            cout << -1 << '\n';
            continue;
        }
        if (L == 1) {
            cout << -1 << '\n';
            continue;
        }
        ans.push_back(make_pair(nodes[0].pos, nodes[n - L].pos));
        --nodes[0].deg;
        ans.push_back(make_pair(nodes[n - L - 1].pos, nodes[n - L + 1].pos));
        --nodes[n - L - 1].deg;
        int idx = 0;
        for (int i = n - L + 2; i < n; ++i) {
            while (idx < n - L && nodes[idx].deg <= 0) {
                ++idx;
            }
            if (idx == n - L) {
                flag = false;
                break;
            }
            --nodes[idx].deg;
            ans.push_back(make_pair(nodes[idx].pos, nodes[i].pos));
        }
        for (int i = 0; i < n; ++i) {
            if (nodes[i].deg < 0) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            cout << -1 << '\n';
            continue;
        }
        for (pair<int, int>& p : ans) {
            cout << p.first << " " << p.second << '\n';
        }
    }

    return 0;
}