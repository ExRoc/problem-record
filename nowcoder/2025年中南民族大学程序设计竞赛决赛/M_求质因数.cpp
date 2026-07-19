#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, p;
    cin >> n >> p;
    long long ans = 0;
    while (n > 0) {
        ans += (n /= p);
    }
    cout << ans << '\n';

    return 0;
}