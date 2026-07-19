#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        if (s[i] != s[n - i - 1]) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';

    return 0;
}