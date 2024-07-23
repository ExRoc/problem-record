#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100 + 100;
int T, n, x;
int num[maxn];

bool judge(int v) {
    for (int i = 1; i <= n; ++i) {
        if (num[i] - num[i - 1] > v) {
            return false;
        }
    }
    if ((x - num[n]) * 2 > v) {
        return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n >> x;
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
        }
        int ans = 2 * x;
        for (int i = 0; i <= 2 * x; ++i) {
            if (judge(i)) {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
