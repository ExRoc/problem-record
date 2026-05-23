#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        if (n % 4 == 0 || n <= 1) {
            cout << n + 1 << '\n';
        } else {
            cout << n << '\n';
        }
    }

    return 0;
}