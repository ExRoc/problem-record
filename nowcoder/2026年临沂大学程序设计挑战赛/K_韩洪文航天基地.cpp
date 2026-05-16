#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, int>> lr(n);
    for (int i = 0; i < n; ++i) {
        cin >> lr[i].first >> lr[i].second;
    }
    sort(lr.begin(), lr.end());
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += upper_bound(lr.begin(), lr.end(),
                           make_pair(lr[i].second, INT_MAX)) -
               lr.begin() - i - 1;
    }
    cout << ans << '\n';

    return 0;
}