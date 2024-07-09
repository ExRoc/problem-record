#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
const LL MOD = 1000000007;
int T, n;
LL ans;
set<int> st;
int a[maxn], b[maxn], c[maxn], fa[maxn], sum[maxn];

void init() {
    ans = 1;
    st.clear();
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        sum[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        sum[c[i]] = c[i] > 0;
    }
}

int fnd(int x) {
    return x == fa[x] ? x : fa[x] = fnd(fa[x]);
}

void unit(int x, int y) {
    x = fnd(x);
    y = fnd(y);
    if (x != y) {
        fa[x] = y;
        sum[y] += sum[x];
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> c[i];
        }
        init();
        for (int i = 1; i <= n; ++i) {
            unit(a[i], b[i]);
        }
        for (int i = 1; i <= n; ++i) {
            if (c[i] > 0 || a[i] == b[i]) {
                continue;
            }
            int f = fnd(a[i]);
            if (st.find(f) == st.end()) {
                st.insert(f);
                if (sum[f] == 0) {
                    ans = ans * 2 % MOD;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
