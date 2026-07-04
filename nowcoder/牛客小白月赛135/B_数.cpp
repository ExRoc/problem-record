#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int a, b;
        a = 9;
        x -= a;
        b = 90 + x % 10;
        a += x - b;
        cout << a << ' ' << b << '\n';
    }

    return 0;
}