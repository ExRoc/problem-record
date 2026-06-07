#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long mod = n % 12;
        if (mod != 10) {
            cout << mod << " " << n - mod << '\n';
            continue;
        }
        if (n >= 22) {
            cout << 22 << " " << n - 22 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}