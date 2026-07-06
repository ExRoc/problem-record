#include <bits/stdc++.h>
using namespace std;

int getBit(long long n) {
    int bit = 0;
    while (n != 0) {
        n >>= 1;
        ++bit;
    }
    return bit;
}

long long solve(long long n) {
    bool limit = true;
    int bit = getBit(n);
    long long last = 1;
    long long left = (1LL << (bit - 1));
    for (int i = bit - 2; i >= 0; --i) {
        long long now = (last ^ 1);
        if (!limit) {
            left |= (now << i);
            last = now;
            continue;
        }
        if (now == 0) {
            if (((n >> i) & 1) == 1) {
                limit = false;
                last = now;
            } else {
                last = 0;
            }
        } else {
            if (((n >> i) & 1) == 1) {
                left |= (now << i);
                last = now;
            } else {
                last = 0;
            }
        }
    }
    return n - left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << solve(n) << '\n';
    }

    return 0;
}