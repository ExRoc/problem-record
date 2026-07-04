#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        stack<int> sta;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            if (!sta.empty() && (sta.top() + a) % 9 == 0) {
                sta.pop();
                ++cnt;
            } else {
                sta.push(a);
            }
        }
        if (cnt % 2 == 0) {
            cout << "No" << '\n';
        } else {
            cout << "Yes" << '\n';
        }
    }

    return 0;
}