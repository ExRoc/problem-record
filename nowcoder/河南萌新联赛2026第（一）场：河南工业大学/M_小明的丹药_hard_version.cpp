#include <bits/stdc++.h>
using namespace std;

void solve(int a, int b, vector<bool>& dp) {
    dp[0] = true;
    vector<int> nums;
    for (int i = 1; i <= a; i <<= 1) {
        nums.push_back(3 * i);
        a -= i;
    }
    if (a != 0) {
        nums.push_back(3 * a);
    }
    for (int i = 1; i <= b; i <<= 1) {
        nums.push_back(2 * i);
        b -= i;
    }
    if (b != 0) {
        nums.push_back(2 * b);
    }
    for (int i = 0; i < (int)nums.size(); ++i) {
        for (int j = dp.size() - 1; j >= nums[i]; --j) {
            dp[j] = (dp[j] || dp[j - nums[i]]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int top = min(3 * a + 2 * b, 3 * c + 2 * d);
        vector<vector<bool>> dp(2, vector<bool>(top + 1, false));
        solve(a, b, dp[0]);
        solve(c, d, dp[1]);
        int ans = 0;
        for (int i = 0; i <= top; ++i) {
            if (dp[0][i] && dp[1][i]) {
                ans = i;
            }
        }
        cout << ans * 2 << '\n';
    }

    return 0;
}