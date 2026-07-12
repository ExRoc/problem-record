#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k;
    cin >> k;
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << k * k + k * abs(c - a) + k * abs(d - b) << '\n';

    return 0;
}