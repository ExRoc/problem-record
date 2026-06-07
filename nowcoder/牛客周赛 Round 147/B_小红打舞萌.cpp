#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int x;
    cin >> x;
    x /= 5;
    cout << x / 2 * 7 + x % 2 * 4 << '\n';

    return 0;
}