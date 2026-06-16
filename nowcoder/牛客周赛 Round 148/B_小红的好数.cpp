#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(false);

    long long n;
    cin >> n;
    for (long long i = 2; i <= n; ++i) {
        if (n % i == 0) {
            if (n % (i * i) == 0) {
                cout << i << ' ' << n / i / i << endl;
                return 0;
            }
            long long q = i;
            n /= i;
            long long low = 1;
            long long high = n + 1;
            while (high - low > 1) {
                long long mid = (high + low) / 2;
                if (mid <= n / mid) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
            cout << low << ' ' << q << endl;
            return 0;
        }
    }

    return 0;
}