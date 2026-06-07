
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int cnt, l, r;

    Node() {}

    Node(int cnt, int l, int r) : cnt(cnt), l(l), r(r) {}

    bool operator<(const Node& other) const { return cnt < other.cnt; }
};

void solve(int l, int n, const string& s, vector<Node>& vct, const string& p) {
    int r = l;
    for (char ch : p) {
        if (s[r] == ch) {
            vct.push_back(Node((int)p.length() - (r - l + 1), l, r));
            ++r;
            if (r == n) {
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<Node> greet, invite;
    greet.push_back({5, -1, -1});
    invite.push_back({6, n, n});
    for (int i = 0; i < n; ++i) {
        solve(i, n, s, greet, "greet");
        solve(i, n, s, invite, "invite");
    }
    sort(greet.begin(), greet.end());
    sort(invite.begin(), invite.end());
    int ans = 11;
    for (const Node& nodeG : greet) {
        for (const Node& nodeI : invite) {
            if (nodeG.r < nodeI.l || nodeG.l > nodeI.r) {
                ans = min(ans, nodeG.cnt + nodeI.cnt);
                break;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}