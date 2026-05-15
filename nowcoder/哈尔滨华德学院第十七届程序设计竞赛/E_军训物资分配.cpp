#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, W;
    cin >> n >> W;
    vector<long long> dp(W + 1);
    for (int i = 1; i <= n; ++i) {
        int w;
        long long v;
        cin >> w >> v;
        for (int j = W; j >= w; --j) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    cout << dp[W] << '\n';

    return 0;
}