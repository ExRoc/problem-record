#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    if (n > 3) {
        cout << -1 << '\n';
        return 0;
    }
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    if (n == 2) {
        cout << "1 2" << '\n' << "3 4" << '\n';
        return 0;
    }
    cout << "1 2 3" << '\n' << "5 4 6" << '\n' << "7 8 9" << '\n';

    return 0;
}