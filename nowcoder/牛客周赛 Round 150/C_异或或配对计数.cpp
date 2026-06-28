#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long x, y;
        cin >> x >> y;
        long long ans = 1;
        for (int i = 0; i < 35; ++i) {
            int bitX = ((x >> i) & 1);
            int bitY = ((y >> i) & 1);
            if (bitX == 1) {
                if (bitY == 0) {
                    ans = 0;
                } else {
                    ans *= 2;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}