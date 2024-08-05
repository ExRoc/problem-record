#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int n, x;
LL ans;
LL cnt[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        ++cnt[x];
    }
    for (int i = 1; i < maxn; ++i) {
        for (int j = i; j < maxn; j += i) {
            ans += cnt[i] * cnt[j / i] * cnt[j];
        }
    }
    cout << ans << endl;

    return 0;
}
