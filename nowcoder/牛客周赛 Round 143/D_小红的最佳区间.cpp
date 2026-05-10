#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l, r;

    Node() {}

    Node(int l, int r) : l(l), r(r) {}

    bool operator<(const Node& other) const { return false; }
};

bool cmpL(const Node& a, const Node& b) {
    return a.l == b.l ? a.r < b.r : a.l < b.l;
}

bool cmpR(const Node& a, const Node& b) {
    return a.r == b.r ? a.l < b.l : a.r < b.r;
}

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<Node> nodeL(n), nodeR(n);
    for (int i = 0; i < n; ++i) {
        cin >> nodeL[i].l >> nodeL[i].r;
        nodeR[i] = nodeL[i];
    }
    sort(nodeL.begin(), nodeL.end(), cmpL);
    sort(nodeR.begin(), nodeR.end(), cmpR);
    int r = 0;
    multiset<int> st;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int L = nodeR[i].r;
        while (r < n && nodeL[r].l <= L + k) {
            st.insert(nodeL[r].r);
            ++r;
        }
        while (!st.empty() && *st.begin() < L) {
            st.erase(st.begin());
        }
        ans = max(ans, (int)st.size());
    }
    cout << ans << '\n';

    return 0;
}