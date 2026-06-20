#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int X, Y;
    cin >> X >> Y;
    int gcd = __gcd(X, Y);
    X /= gcd;
    Y /= gcd;
    if (X == 16 && Y == 9) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }

    return 0;
}