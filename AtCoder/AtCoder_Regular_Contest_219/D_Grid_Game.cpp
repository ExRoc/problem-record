#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int sg = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int x;
                cin >> x;
                if ((i + j) % 2 == 1) {
                    sg ^= x % (k + 1);
                }
            }
        }
        if (sg == 0) {
            cout << "Bob" << '\n';
        } else {
            cout << "Alice" << '\n';
        }
    }

    return 0;
}