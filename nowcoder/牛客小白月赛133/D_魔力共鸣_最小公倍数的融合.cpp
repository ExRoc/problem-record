#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, int> cnts;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            for (int j = 1; j <= a / j; ++j) {
                if (a % j == 0) {
                    ++cnts[j];
                    if (a / j != j) {
                        ++cnts[a / j];
                    }
                }
            }
        }
        cnts.erase(1);
        if (cnts.empty()) {
            cout << -1 << '\n';
            continue;
        }
        int mx = 0;
        for (auto [_, cnt] : cnts) {
            mx = max(cnt, mx);
        }
        cout << n - mx << '\n';
    }

    return 0;
}