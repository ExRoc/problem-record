#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
const int Log = 40;
int n, q, t, b;
int num[maxn];
LL dpSum[maxn][Log], dpIdx[maxn][Log];

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
        dpSum[i][0] = i;
        dpIdx[i][0] = num[i];
    }
    for (int j = 1; j < Log; ++j) {
        for (int i = 1; i <= n; ++i) {
            dpSum[i][j] = dpSum[i][j - 1] + dpSum[dpIdx[i][j - 1]][j - 1];
            dpIdx[i][j] = dpIdx[dpIdx[i][j - 1]][j - 1];
        }
    }
    while (q--) {
        cin >> t >> b;
        LL ans = 0;
        for (int j = Log - 1; j >= 0; --j) {
            if (t >= (1LL << j)) {
                ans += dpSum[b][j];
                b = dpIdx[b][j];
                t -= (1LL << j);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
