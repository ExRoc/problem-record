#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    if (n % 2 == 1) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (i < n / 2) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << '\n';

    return 0;
}