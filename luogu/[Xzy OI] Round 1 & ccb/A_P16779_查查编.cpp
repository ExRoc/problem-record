#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long a, x;
        cin >> a >> x;
        long long lcnt = x - a;
        if (lcnt == 0) {
            cout << a << '\n';
            continue;
        }
        int level = 0;
        while (lcnt != 0) {
            ++level;
            lcnt >>= 1;
        }
        lcnt = x - a;
        long long rcnt = 0;
        if (lcnt == (1LL << level) - 1) {
            rcnt = lcnt;
        } else {
            rcnt = (1LL << (level - 1)) - 1;
        }
        long long tot = lcnt + rcnt + 1;
        cout << a + tot - 1 << '\n';
    }

    return 0;
}