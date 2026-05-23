#include <bits/stdc++.h>
using namespace std;

int cal(int x1, int y1, int z1, int x2, int y2, int z2) {
    int dis =
        (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
    int sq = sqrt(dis);
    for (int i = sq; i <= sq + 100; ++i) {
        if (i * i >= dis) {
            return i;
        }
    }
    return sq;
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, m, p;
        cin >> n >> m >> p;
        int mx = 0;
        int x, y, z;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int k = 1; k <= p; ++k) {
                    int a;
                    cin >> a;
                    if (a > mx) {
                        mx = a;
                        x = i;
                        y = j;
                        z = k;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int k = 1; k <= p; ++k) {
                    ans = max(ans, cal(x, y, z, i, j, k));
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}