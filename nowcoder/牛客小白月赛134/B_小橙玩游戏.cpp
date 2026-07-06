#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n <= 2) {
            cout << "xiaocheng" << '\n';
        } else {
            cout << "xiaoju" << '\n';
        }
    }

    return 0;
}