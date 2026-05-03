#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    int x, y;
    cin >> T;
    while (T--) {
        cin >> x >> y;
        int a = x % 2;
        int b = y % 2;
        if (a + b >= 2) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }

    return 0;
}
