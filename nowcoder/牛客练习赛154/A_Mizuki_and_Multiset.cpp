#include <bits/stdc++.h>
using namespace std;

int solve(int x) {
    if (x % 2 == 0) {
        return x / 2;
    }
    if (x % 3 == 0) {
        return solve(x - 3) + 1;
    }
    for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0) {
            if (x / i >= 3) {
                return solve(x - 3 * i) + solve(i * 3);
            } else {
                return solve(x - i) + solve(i);
            }
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << solve(n) << '\n';
    }

    return 0;
}
