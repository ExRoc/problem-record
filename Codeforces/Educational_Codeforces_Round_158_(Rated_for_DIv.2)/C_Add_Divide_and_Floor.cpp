#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int T, n, mn, mx, ans;
int num[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n;
        mx = 0;
        mn = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
            mx = max(mx, num[i]);
            mn = min(mn, num[i]);
        }
        ans = 0;
        while (mx != mn) {
            ++ans;
            mx = (mx + mn) / 2;
        }
        cout << ans << endl;
        if (ans <= n) {
            for (int i = 0; i < ans; ++i) {
                cout << mn << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
