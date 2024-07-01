#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 250000 + 100;
const LL MOD = 1000000007;
int n;
LL ans, tmp;
char str[maxn];

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif

    cin >> n >> str;
    ans = 1;
    for (int i = 2; i <= n; ++i) {
        if (str[i] != str[i - 1] && str[i] == str[i - 2]) {
            ++tmp;
        } else {
            tmp += 2;
            ans = (ans * ((tmp + 1) / 2)) % MOD;
            tmp = 0;
        }
    }
    cout << ans << endl;

    return 0;
}
