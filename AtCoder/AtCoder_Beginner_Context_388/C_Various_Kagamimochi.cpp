#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 500000 + 100;
int n;
LL ans;
int num[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
    }
    for (int i = 1; i < n; ++i) {
        int idx = lower_bound(num + 1, num + 1 + n, num[i] * 2) - num;
        ans += (n - idx) + 1;
    }
    cout << ans << endl;

    return 0;
}
