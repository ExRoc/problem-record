#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int x, y, z;
    cin >> x >> y >> z;
    cout << (z + y - 1) / y * x << '\n';

    return 0;
}