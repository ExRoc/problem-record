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
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        vector<int> ans;
        bool flag = true;
        for (int i = n; i >= 1; --i) {
            if (flag == (a[i] > 0)) {
                ans.push_back(i);
                flag = !flag;
            }
        }
        cout << ans.size() << '\n';
        for (int idx : ans) {
            cout << idx << " ";
        }
        cout << '\n';
    }

    return 0;
}