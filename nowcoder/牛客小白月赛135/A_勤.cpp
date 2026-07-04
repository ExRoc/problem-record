#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, n;
    cin >> n >> a >> b;
    cout << max(0, a + b - n) << '\n';

    return 0;
}