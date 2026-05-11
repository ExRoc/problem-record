#include <bits/stdc++.h>
using namespace std;

void dfs(int root, int l, int r, vector<int>& q, vector<int>& p) {
    if (l > r) {
        return;
    }
    int nxt;
    for (int i = l; i <= r; i = nxt) {
        cout << p[root] << " " << p[q[i]] << '\n';
        nxt = i + 1;
        int mx = q[i];
        for (int j = i + 1; j <= r; ++j) {
            if (q[j] < q[i]) {
                break;
            }
            mx = max(mx, q[j]);
            if (mx - q[i] == j - i) {
                nxt = j + 1;
            }
        }
        dfs(q[i], i + 1, nxt - 1, q, p);
    }
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        vector<int> id(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
            id[p[i]] = i;
        }
        vector<int> q(n + 1), qMap(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> q[i];
            qMap[i] = id[q[i]];
        }
        dfs(1, 2, n, qMap, p);
    }

    return 0;
}