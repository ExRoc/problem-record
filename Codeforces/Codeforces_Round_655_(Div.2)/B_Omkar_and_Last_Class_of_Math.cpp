#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
int T;
LL n, ansa, ansb;

LL lcm(LL a, LL b) {
    return a / __gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n;
        ansa = 1;
        ansb = n - 1;
        for (LL i = 2; i * i <= n; ++i) {
            if (n % i != 0) {
                continue;
            }
            if (lcm(ansa, ansb) > lcm(n / i, n - n / i)) {
                ansa = n / i;
                ansb = n - n / i;
            }
        }
        cout << ansa << " " << ansb << endl;
    }

    return 0;
}
