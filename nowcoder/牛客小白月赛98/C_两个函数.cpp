#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
const LL MOD = 998244353;
int T;
LL a, x;

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> a >> x;
        if (x == 1) {
            cout << a % MOD << endl;
            continue;
        }
        --x;
        x = (1 + x) * x / 2 % MOD;
        x = x * a % MOD * a % MOD;
        cout << x << endl;
    }

    return 0;
}
