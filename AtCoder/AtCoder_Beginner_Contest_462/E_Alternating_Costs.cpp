#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        long long A, B, X, Y;
        cin >> A >> B >> X >> Y;
        X = abs(X);
        Y = abs(Y);
        if (B > 3 * A) {
            B = 3 * A;
        }
        if (A > 3 * B) {
            A = 3 * B;
        }
        long long ans = min(X, Y) * 2 * min(A, B);
        if (X > Y) {
            ans += (X - Y) % 2 * A + (X - Y) / 2 * (A + B);
        } else {
            ans += (Y - X) % 2 * B + (Y - X) / 2 * (A + B);
        }
        cout << ans << '\n';
    }

    return 0;
}