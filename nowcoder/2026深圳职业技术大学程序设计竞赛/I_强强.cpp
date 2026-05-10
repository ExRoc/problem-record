#include <bits/stdc++.h>
using namespace std;

long long cal(long long x) {
    long long ans = 0;
    long long ten = 1;
    while (x != 0) {
        ans += 9 * ten - (9 - x % 10);
        x /= 10;
        ten *= 10;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ans += cal(x);
        }
        cout << ans << '\n';
    }

    return 0;
}