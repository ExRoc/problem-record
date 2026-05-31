#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<long long> sum(n + 1);
        vector<long long> absSum(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
            absSum[i] = absSum[i - 1] + abs(a[i]);
        }
        int idx = 0;
        long long maxSum = sum[n];
        for (int i = 1; i <= n; ++i) {
            if (a[i] > 0) {
                if (absSum[i - 1] - a[i] + sum[n] - sum[i] > maxSum) {
                    idx = i;
                    maxSum = absSum[i - 1] - a[i] + sum[n] - sum[i];
                }
            }
        }
        if (idx == 0) {
            cout << 0 << '\n' << '\n';
            continue;
        }
        vector<int> ans;
        bool isPositive = true;
        for (int i = idx - 1; i >= 1; --i) {
            if ((a[i] > 0) == isPositive) {
                ans.push_back(i);
                isPositive = !isPositive;
            }
        }
        ans.push_back(idx);
        cout << ans.size() << '\n';
        for (int idx : ans) {
            cout << idx << ' ';
        }
        cout << '\n';
    }

    return 0;
}