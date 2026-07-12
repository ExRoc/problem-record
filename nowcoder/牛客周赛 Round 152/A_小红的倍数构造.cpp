#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    cin >> x;
    long long ten = 1;
    long long tmp = x;
    while (tmp != 0) {
        ten = ten * 10;
        tmp /= 10;
    }
    cout << x * ten + x << '\n';

    return 0;
}