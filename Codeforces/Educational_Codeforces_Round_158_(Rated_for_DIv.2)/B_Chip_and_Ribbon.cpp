#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int T, n;
LL ans;
int num[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n;
        ans = 0;
        num[0] = 1;
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
            if (num[i] > num[i - 1]) {
                ans += num[i] - num[i - 1];
            }
        }
        cout << ans << endl;
    }

    return 0;
}
