#include <bits/stdc++.h>
using namespace std;

struct Node {
    __int128_t x, w;

    Node() {}

    Node(long long x, long long w) : x(x), w(w) {}

    bool operator<(const Node& other) const { return false; }
};

string toString(__int128_t x) {
    if (x == 0) {
        return "0";
    }
    string ans;
    while (x != 0) {
        ans.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long ll, WW;
    cin >> n >> ll >> WW;
    __int128_t l = ll, W = WW;
    vector<Node> nodes;
    __int128_t wsum = 0;
    __int128_t xwsum = 0;
    for (int i = 0; i < n; ++i) {
        long long x, w;
        cin >> x >> w;
        nodes.push_back(Node(x, w));
        wsum += w;
        xwsum += w * x;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        __int128_t p = (W * l + 2 * (xwsum - nodes[i].w * nodes[i].x)) /
                       (2 * (wsum - nodes[i].w) + 2 * W);
        if (p * (2 * (wsum - nodes[i].w) + 2 * W) ==
            (W * l + 2 * (xwsum - nodes[i].w * nodes[i].x))) {
            ++ans;
        }
    }
    cout << ans << '\n';

    return 0;
}