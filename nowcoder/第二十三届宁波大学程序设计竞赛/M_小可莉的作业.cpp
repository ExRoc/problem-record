#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    for (int i = 2; i < x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);

    int x;
    cin >> x;
    int ans;
    for (int i = 2; i <= 1000; ++i) {
        if (isPrime(i)) {
            --x;
        }
        if (x == 0) {
            ans = i;
            break;
        }
    }
    cout << "1 " << ans << '\n';

    return 0;
}