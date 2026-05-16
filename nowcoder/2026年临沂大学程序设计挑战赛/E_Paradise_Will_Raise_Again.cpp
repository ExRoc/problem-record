#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string str;
    cin >> str;
    long long cntu = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (str[i] == 'U') {
            ++cntu;
        }
    }
    long long cntl = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'L') {
            ++cntl;
            continue;
        }
        if (str[i] == 'Y') {
            ans += cntl * cntu;
            continue;
        }
        if (str[i] == 'U') {
            --cntu;
        }
    }
    cout << ans << '\n';

    return 0;
}