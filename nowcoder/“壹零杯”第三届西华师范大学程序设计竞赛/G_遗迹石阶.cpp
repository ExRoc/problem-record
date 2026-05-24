#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<bool> isBroken(N + 1);
    for (int i = 0; i < M; ++i) {
        int b;
        cin >> b;
        isBroken[b] = true;
    }
    vector<long long> dp(N + 1);
    dp[0] = 1;
    for (int i = 1; i <= N; ++i) {
        if (isBroken[i]) {
            continue;
        }
        dp[i] = dp[i - 1];
        if (i >= 2) {
            dp[i] += dp[i - 2];
        }
    }
    cout << dp[N] << '\n';

    return 0;
}