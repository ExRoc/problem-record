#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 300000 + 100;
int n;
LL ans;
LL num[maxn], l[maxn], r[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
    }
    for (int i = 1; i <= n; ++i) {
        l[i] = num[i] - (num[1] + i - 1);
        l[i] = max(l[i - 1], l[i]);
        int idx = n - i + 1;
        r[idx] = num[idx] - (num[n] + i - 1);
        r[idx] = max(r[idx], r[idx + 1]);
    }
    ans = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        LL a = 0;
        LL b = 0;
        LL c = 0;
        if (i != 1) {
            a = l[i - 1] + num[1] + n - 1;
        }
        if (i != n) {
            b = r[i + 1] + num[n] + n - 1;
        }
        c = num[i];
        ans = min(ans, max({a, b, c}));
    }
    cout << ans << endl;

    return 0;
}
