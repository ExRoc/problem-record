#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c;
    cin >> a >> b >> c;
    if (a + b == c) {
        cout << "YES" << '\n';
        return 0;
    }
    if ((a != 0 && (c - b) % a == 0) || (b != 0 && (c - a) % b == 0) ||
        (c != 0 && (a + b) % c == 0)) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }

    return 0;
}