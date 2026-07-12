#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> ans = {0, 1, 2, 3};
    for (int i = 4; i <= 50; ++i) {
        ans.push_back(ans.back() * 2);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 2) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}