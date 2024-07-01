#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int T, n;
LL num[maxn];

bool judge(LL mid) {
    int idx = upper_bound(num + 1, num + 1 + n, num[1] + mid * 2) - num;
    idx = upper_bound(num + idx, num + 1 + n, num[idx] + 2 * mid) - num;
    idx = upper_bound(num + idx, num + 1 + n, num[idx] + 2 * mid) - num;
    return idx == n + 1;
}

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
        }
        sort(num + 1, num + 1 + n);
        LL high = num[n] - num[1];
        LL low = -1;
        LL mid;
        while (high - low > 1) {
            mid = (high + low) >> 1;
            if (judge(mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        cout << high << endl;
    }

    return 0;
}
