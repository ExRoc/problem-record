#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        long long n, x, y;
        cin >> n >> x >> y;
        if (x + y <= n) {
            cout << x + y << '\n';
            continue;
        }
        cout << n - (x + y - n) << '\n';
    }

    return 0;
}