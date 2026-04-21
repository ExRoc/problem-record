#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long LL;
const int maxn = 100000 + 100;
int T;
LL n, c, w;
LL sum[maxn];

void init() {
    for (int i = 1; i < maxn; ++i) {
        sum[i] = sum[i - 1] + i;
    }
}

int main() {
    ios::sync_with_stdio(false);

    init();
    cin >> T;
    while (T--) {
        cin >> n >> c >> w;
        if (w % c != 0) {
            cout << -1 << endl;
            continue;
        }
        if (w == 0) {
            cout << 0 << endl;
            continue;
        }
        w /= c;
        LL sumn = (1 + n) * n / 2;
        if (w > sumn) {
            cout << -1 << endl;
            continue;
        }
        bool flag = false;
        for (LL i = 0; i <= n; ++i) {
            int idx = upper_bound(sum, sum + n + 1, w + sum[i]) - sum - 1;
            if (sum[idx] - sum[i] == w) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }

    return 0;
}
