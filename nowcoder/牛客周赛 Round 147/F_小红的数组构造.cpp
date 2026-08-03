#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int INF = 0x3f3f3f3f;
    int T;
    cin >> T;
    while (T--) {
        int n, x, k;
        cin >> n >> x >> k;
        if (k < n || k > 1LL * n * x) {
            cout << "NO" << '\n';
            continue;
        }
        vector<int> nums;
        int xx = x;
        while (xx != 0) {
            nums.push_back(x / xx);
            xx = x / (x / xx + 1);
        }
        int d = k - n;
        for (int& num : nums) {
            --num;
        }
        vector<int> dp(d + 1, INF);
        vector<int> pre(d + 1, 0);
        dp[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = nums[i]; j <= d; ++j) {
                if (dp[j - nums[i]] + 1 < dp[j]) {
                    dp[j] = dp[j - nums[i]] + 1;
                    pre[j] = j - nums[i];
                }
            }
        }
        if (dp[d] > n) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        vector<int> ans;
        int idx = d;
        while (idx != 0) {
            ans.push_back(x / (idx - pre[idx] + 1));
            idx = pre[idx];
        }
        while (ans.size() < n) {
            ans.push_back(x);
        }
        for (int a : ans) {
            cout << a << ' ';
        }
        cout << '\n';
    }

    return 0;
}