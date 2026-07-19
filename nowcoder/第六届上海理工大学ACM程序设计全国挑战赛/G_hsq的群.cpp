#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<set<int>> groups(m);
        for (int i = 0; i < m; ++i) {
            int k;
            cin >> k;
            for (int j = 0; j < k; ++j) {
                int id;
                cin >> id;
                groups[i].insert(id);
            }
        }
        while (q--) {
            int u, v;
            cin >> u >> v;
            int ans = 0;
            for (int i = 0; i < m; ++i) {
                if (groups[i].find(u) != groups[i].end() &&
                    groups[i].find(v) != groups[i].end()) {
                    ++ans;
                }
            }
            cout << ans << '\n';
        }
    }

    return 0;
}