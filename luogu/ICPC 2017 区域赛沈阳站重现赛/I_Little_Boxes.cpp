#include <bits/stdc++.h>
using namespace std;

void output(__int128_t x) {
    if (x == 0) {
        cout << 0 << '\n';
        return;
    }
    string ans;
    while (x != 0) {
        ans.push_back((char)(x % 10 + '0'));
        x /= 10;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        __int128_t ans = 0;
        for (int i = 0; i < 4; ++i) {
            long long x;
            cin >> x;
            ans += x;
        }
        output(ans);
    }

    return 0;
}