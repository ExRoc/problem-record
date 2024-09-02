#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1000 + 100;
int n, m, u, v, ans;
int num[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        ans += min(num[u], num[v]);
    }
    cout << ans << endl;

    return 0;
}
