#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        int ans = -1;
        while (n != 0) {
            ans += (n & 1);
            n >>= 1;
            ++ans;
        }
        cout << ans << '\n';
    }

    return 0;
}
