#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long x, y;
        cin >> x >> y;
        int who = 1;
        while (x >= 2 || y >= 2) {
            if (x < y) {
                swap(x, y);
            }
            y += x / 2;
            if (x / 2 % 2 == 1) {
                who ^= 1;
            }
            x %= 2;
        }
        if (who == 1) {
            cout << "Bob" << '\n';
        } else {
            cout << "Alice" << '\n';
        }
    }

    return 0;
}