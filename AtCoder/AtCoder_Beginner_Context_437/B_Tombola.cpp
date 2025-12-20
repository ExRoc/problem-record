#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100 + 100;
int n, m, nn, ans, tmp, x;
int num[maxn][maxn];
set<int> st;

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m >> nn;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> num[i][j];
        }
    }
    for (int i = 0; i < nn; ++i) {
        cin >> x;
        st.insert(x);
    }
    for (int i = 1; i <= n; ++i) {
        int tmp = 0;
        for (int j = 1; j <= m; ++j) {
            if (st.find(num[i][j]) != st.end()) {
                ++tmp;
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}
