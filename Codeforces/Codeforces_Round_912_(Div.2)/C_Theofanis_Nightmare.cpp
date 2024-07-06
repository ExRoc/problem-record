#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
int T, n;
LL ans;
LL num[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
        }
        ans = 0;
        num[n + 1] = 0;
        for (int i = n; i >= 1; --i) {
            num[i] += num[i + 1];
            if (num[i] >= 0) {
                ans += num[i];
            }
        }
        if (num[1] <= 0) {
            ans += num[1];
        }
        cout << ans << endl;
    }

    return 0;
}
