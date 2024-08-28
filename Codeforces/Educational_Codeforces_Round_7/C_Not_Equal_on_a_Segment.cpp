#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int n, m, l, r, x;
int num[maxn], nxt[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
    }
    for (int i = n; i >= 1; --i) {
        if (num[i] == num[i + 1]) {
            nxt[i] = nxt[i + 1];
        } else {
            nxt[i] = i + 1;
        }
    }
    while (m--) {
        cin >> l >> r >> x;
        if (num[l] != x) {
            cout << l << endl;
            continue;
        }
        if (nxt[l] > r) {
            cout << -1 << endl;
        } else {
            cout << nxt[l] << endl;
        }
    }

    return 0;
}
