#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        long long a, b;
        cin >> a >> b;
        int ans = -1;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (__gcd(a + i, b + j) != 1) {
                    ans = i + j;
                    break;
                }
            }
            if (ans != -1) {
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}