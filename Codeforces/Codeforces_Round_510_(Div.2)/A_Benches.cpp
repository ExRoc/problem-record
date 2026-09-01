#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int mn, mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int mm = m;
    for (int i = 0; i < n; ++i) {
        int tmp = min(mx - a[i], mm);
        mm -= tmp;
        a[i] += tmp;
    }
    mn = mx;
    if (mm != 0) {
        mn += (mm + n - 1) / n;
    }
    cout << mn << ' ' << mx + m << '\n';

    return 0;
}