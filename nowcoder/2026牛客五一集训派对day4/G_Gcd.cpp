#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0) {
            if (x == 0 || y == 0) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
            continue;
        }
        if (z % __gcd(x, y) == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}