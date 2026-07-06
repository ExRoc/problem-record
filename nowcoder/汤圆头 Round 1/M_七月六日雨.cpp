#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;
    int d = 6;
    long long ans = 0;
    for (int i = 0; i < n.length(); i += d) {
        d = 13 - d;
        long long tmp = 0;
        for (int j = 0; j < d; ++j) {
            if (i + j < n.length()) {
                tmp = tmp * 10 + n[i + j] - '0';
            } else {
                break;
            }
        }
        ans += tmp;
    }
    cout << ans << '\n';

    return 0;
}