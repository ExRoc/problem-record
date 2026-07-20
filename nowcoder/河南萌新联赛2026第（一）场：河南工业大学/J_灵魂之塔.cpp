#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<bool> fromLeft(n, false), fromRight(n, false);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i] = abs(a[i]) % 2;
            if (i == 0) {
                fromLeft[i] = true;
                continue;
            }
            if (fromLeft[i - 1] && a[i] != a[i - 1]) {
                fromLeft[i] = true;
            }
        }
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) {
                fromRight[i] = true;
                continue;
            }
            if (fromRight[i + 1] && a[i] != a[i + 1]) {
                fromRight[i] = true;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                if (fromRight[i + 1]) {
                    ++ans;
                }
            } else if (i == n - 1) {
                if (fromLeft[i - 1]) {
                    ++ans;
                }
            } else {
                if (fromLeft[i - 1] && fromRight[i + 1] &&
                    a[i - 1] != a[i + 1]) {
                    ++ans;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}