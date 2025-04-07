#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
LL x;
LL fac[100];

int main() {
    ios::sync_with_stdio(false);

    fac[0] = 1;
    for (int i = 1; i <= 20; ++i) {
        fac[i] = fac[i - 1] * i;
    }
    cin >> x;
    for (int i = 1; i <= 20; ++i) {
        if (x == fac[i]) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
