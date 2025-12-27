#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
int n, m, ans;
string s, t;

int solve(int idx) {
    int ret = 0;
    for (int i = 0; i < m; ++i) {
        int ii = idx + i;
        ret += ((s[ii] - '0' - (t[i] - '0')) % 10 + 10) % 10;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    ans = INT_MAX;
    cin >> n >> m;
    cin >> s >> t;
    for (int i = 0; i + m - 1 < n; ++i) {
        ans = min(ans, solve(i));
    }
    cout << ans << endl;

    return 0;
}
