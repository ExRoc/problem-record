#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1]) {
            ++cnt;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int p;
        char c;
        cin >> p >> c;
        --p;
        int before = (s[p] != s[n - p - 1]);
        s[p] = c;
        int after = (s[p] != s[n - p - 1]);
        cnt += after - before;
        if (cnt == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}