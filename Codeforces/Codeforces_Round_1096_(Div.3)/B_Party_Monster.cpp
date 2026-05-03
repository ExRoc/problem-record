#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T, n;
    string str;
    cin >> T;
    while (T--) {
        cin >> n >> str;
        int l = 0;
        int r = 0;
        for (char ch : str) {
            if (ch == '(') {
                ++l;
            } else {
                ++r;
            }
        }
        if (l == r) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
