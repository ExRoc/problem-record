#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int T, n, mn, g;
LL ans;
int num[maxn];
set<int> st;

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        ans = 0;
        st.clear();
        cin >> n;
        mn = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
            num[i] = -num[i];
            mn = min(mn, num[i]);
        }
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        g = 0;
        for (int i = 1; i <= n; ++i) {
            num[i] -= mn;
            g = __gcd(num[i], g);
        }
        sort(num + 1, num + 1 + n);
        for (int i = 1; i <= n; ++i) {
            ans += num[i] / g;
            st.insert(num[i] / g);
        }
        for (int i = 1; i <= n + 1; ++i) {
            if (st.find(i) == st.end()) {
                ans += i;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
