#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 300000 + 100;
int n;
LL ans;
LL a[maxn], b[maxn], c[maxn], mx[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        b[i] += b[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        c[i] += c[i - 1];
    }
    for (int i = n - 1; i >= 1; --i) {
        mx[i] = max(mx[i + 1], c[n] - c[i] + b[i]);
    }
    for (int i = 1; i <= n - 2; ++i) {
        ans = max(ans, a[i] + mx[i + 1] - b[i]);
    }
    cout << ans << endl;

    return 0;
}
