#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        if (x == 0) {
            cout << y / 2 * 2 * (y - y / 2) * 2 << '\n';
        } else {
            int sum = x + 2 * y;
            cout << sum / 2 * (sum - sum / 2) << '\n';
        }
    }

    return 0;
}