#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int maxAns = 0;
    for (int i = 1; i < n; ++i) {
        maxAns = __gcd(maxAns, a[i] - a[i - 1]);
    }
    if (maxAns == 1) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> ans;
    for (int i = 2; i <= maxAns / i; ++i) {
        if (maxAns % i == 0) {
            ans.push_back(i);
            if (maxAns / i != i) {
                ans.push_back(maxAns / i);
            }
        }
    }
    ans.push_back(maxAns);
    if (ans.empty()) {
        cout << -1 << '\n';
        return 0;
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}