#include <bits/stdc++.h>
using namespace std;

int cal(long long x) {
    if (x >= 2) {
        return 2;
    }
    if (x == 1) {
        return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        long long l, r;
        cin >> l >> r;
        assert(l >= 1 && l <= r);
        assert(r >= l && r <= 1000000000);
        cout << cal(r) - cal(l - 1) << '\n';
    }

    return 0;
}