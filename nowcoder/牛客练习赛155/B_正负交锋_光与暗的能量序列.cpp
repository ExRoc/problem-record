#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n <= 2) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }

    return 0;
}