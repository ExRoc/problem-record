#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;
    int lenS = s.length();
    int lenT = t.length();
    if (lenS > lenT) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << (t.substr(0, lenS) == s && t.substr(lenT - lenS, lenS) == s ? "YES"
                                                                        : "NO")
         << '\n';

    return 0;
}