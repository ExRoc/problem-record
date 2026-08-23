#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> dp(n + 1);
    vector<int> sum(n + 1);
    map<int, int> mp;
    mp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        sum[i] = sum[i - 1] ^ a[i];
        int pre = sum[i] ^ k;
        if (mp.find(pre) != mp.end()) {
            dp[i] = max(dp[i], dp[mp[pre]] + 1);
        }
        mp[sum[i]] = i;
    }
    cout << dp[n] << '\n';

    return 0;
}