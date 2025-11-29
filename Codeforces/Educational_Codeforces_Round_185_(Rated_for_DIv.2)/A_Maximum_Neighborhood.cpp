#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
int T, n, ans;

bool in(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int cal(int x) {
    int xx = (x - 1) / n;
    int yy = (x - 1) % n;
    int ret = x;
    if (in(xx, yy - 1)) {
        ret += x - 1;
    }
    if (in(xx, yy + 1)) {
        ret += x + 1;
    }
    if (in(xx - 1, yy)) {
        ret += x - n;
    }
    if (in(xx + 1, yy)) {
        ret += x + n;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n;
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                ans = max(ans, cal((i - 1) * n + j - 1 + 1));
            }
        }
        cout << ans << endl;
    }

    return 0;
}
