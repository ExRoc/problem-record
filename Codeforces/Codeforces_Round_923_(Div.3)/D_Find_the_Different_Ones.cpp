#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int T, n, q, l, r, idx;
int num[maxn], nxt[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
        }
        num[n + 1] = 0;
        for (int i = n; i >= 1; --i) {
            if (num[i] != num[i + 1]) {
                nxt[i] = idx = i + 1;
            } else {
                nxt[i] = idx;
            }
        }
        cin >> q;
        while (q--) {
            cin >> l >> r;
            if (nxt[l] <= r) {
                cout << l << " " << nxt[l] << endl;
            } else {
                cout << "-1 -1" << endl;
            }
        }
    }

    return 0;
}
