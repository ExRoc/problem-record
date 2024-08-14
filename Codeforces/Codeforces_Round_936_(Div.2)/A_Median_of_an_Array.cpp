#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
int T, n;
int num[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
        }
        sort(num + 1, num + 1 + n);
        int ans = 0;
        for (int i = (n + 1) / 2; i <= n; ++i) {
            if (num[i] == num[(n + 1) / 2]) {
                ++ans;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
