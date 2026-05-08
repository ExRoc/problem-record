#include <bits/stdc++.h>
using namespace std;

long long solve(long long n) {
    if (n == -1 || n == 0) {
        return 0;
    }
    long long ans = 0;
    for (int i = 0; i < 63; ++i) {
        if (i != 0 && (1LL << i) <= n) {
            ++ans;
        }
        for (int j = 0; j < i; ++j) {
            if ((1LL << i) + (1LL << j) <= n) {
                ++ans;
            } else {
                break;
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        long long l, r;
        cin >> l >> r;
        cout << solve(r) - solve(l - 1) << '\n';
    }

    return 0;
}