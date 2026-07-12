#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> deg(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int u, v;
        cin >> u >> v;
        ++deg[u];
        ++deg[v];
    }
    int x, y;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1) {
            x = i;
        } else if (deg[i] == 3) {
            y = i;
        }
    }
    cout << x << " " << y << '\n';

    return 0;
}