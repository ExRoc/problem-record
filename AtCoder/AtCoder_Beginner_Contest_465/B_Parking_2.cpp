#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, Y, L, R, A, B;
    cin >> X >> Y >> L >> R >> A >> B;
    int ans = 0;
    for (int i = A; i < B; ++i) {
        if (i >= L && i < R) {
            ans += X;
        } else {
            ans += Y;
        }
    }

    cout << ans << '\n';

    return 0;
}