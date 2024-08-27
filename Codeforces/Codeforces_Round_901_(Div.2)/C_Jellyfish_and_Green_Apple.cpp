#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
int T, n, m, g;

int lowbit(int x) {
    return x & -x;
}

int bit(int x) {
    int ret = 0;
    while (x != 1) {
        ++ret;
        x >>= 1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n >> m;
        g = __gcd(n, m);
        n /= g;
        m /= g;
        if (lowbit(m) != m) {
            cout << -1 << endl;
        } else {
            cout << bit(m) << endl;
        }
    }

    return 0;
}
