#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 150 + 100;
int n, m, b, ans, now, l, r;
char str[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);

    now = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> (str[i] + 1);
        r = 1;
        l = m;
        for (int j = 1; j <= m; ++j) {
            if (str[i][j] == 'W') {
                b = i;
                r = max(r, j);
                l = min(l, j);
            }
        }
        if (l <= r) {
            if (i % 2 == 0) {
                if (r <= now) {
                    ans += now - l;
                } else {
                    ans += r - now + r - l;
                }
                now = l;
            } else {
                if (l >= now) {
                    ans += r - now;
                } else {
                    ans += now - l + r - l;
                }
                now = r;
            }
        }
    }
    cout << max(ans + b - 1, 0) << endl;

    return 0;
}
