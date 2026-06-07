
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        long long n, m;
        cin >> n >> m;
        long long high = m + 1;
        long long low = 1;
        while (high - low > 1) {
            long long mid = (high + low) >> 1;
            if (mid <= m / mid) {
                low = mid;
            } else {
                high = mid;
            }
        }
        cout << low + m / low << endl;
    }

    return 0;
}