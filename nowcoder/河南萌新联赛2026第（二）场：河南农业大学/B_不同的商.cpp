#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, y;
    cin >> x >> y;
    y = min(x, y);
    long long i = 1;
    long long ans = 0;
    while (i <= y) {
        long long nextI = x / (x / i) + 1;
        nextI = min(nextI, y + 1);
        ans += (nextI - i) * (x / i);
        i = nextI;
    }
    cout << ans << '\n';

    return 0;
}