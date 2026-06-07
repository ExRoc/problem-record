
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    const int maxNum = 1000000;
    vector<vector<int>> facs(maxNum + 1);
    for (int i = 2; i <= maxNum; ++i) {
        if (!facs[i].empty()) {
            continue;
        }
        for (int j = i; j <= maxNum; j += i) {
            facs[j].push_back(i);
        }
    }
    int n;
    cin >> n;
    vector<pair<int, int>> dp(n + 1);
    vector<int> idx(maxNum + 1, 0);
    vector<int> a(n + 1);
    pair<int, int> lastMax;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp[i] = {0, 1};
        for (int fac : facs[a[i]]) {
            int num = a[i] / fac;
            if (idx[num] == 0) {
                continue;
            }
            if (dp[idx[num]].second + 1 > dp[i].second) {
                dp[i] = {idx[num], dp[idx[num]].second + 1};
            }
        }
        idx[a[i]] = i;
        if (lastMax.second < dp[i].second) {
            lastMax = {i, dp[i].second};
        }
    }
    int idxTmp = lastMax.first;
    vector<int> ans;
    while (idxTmp > 0) {
        ans.push_back(a[idxTmp]);
        idxTmp = dp[idxTmp].first;
    }
    cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}