#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, n;
    cin >> x >> n;
    cout << x - n % x << '\n';

    return 0;
}