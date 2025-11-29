#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int T, n;
LL ans, sum;
LL num[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n;
        sum = 1;
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
            sum += max(num[i] - 1, 0LL);
            ans += (num[i] != 0);
        }
        if (sum >= n) {
            cout << ans << endl;
            continue;
        }
        ans -= n - sum;
        cout << ans << endl;
    }

    return 0;
}
