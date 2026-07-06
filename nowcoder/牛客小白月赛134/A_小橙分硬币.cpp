#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    cin >> a >> b;
    long long sum = a + 2 * b;
    if (sum % 2 == 1) {
        cout << "NO" << '\n';
        return 0;
    }
    if (a > 0) {
        cout << "YES" << '\n';
        return 0;
    }
    if (sum / 2 % 2 == 1) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';

    return 0;
}