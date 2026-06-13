#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    string s;
    getline(cin, s);
    while (T--) {
        getline(cin, s);
        if (s.substr(0, 8) == "Colin : " || s.substr(0, 6) == "Eva : ") {
            cout << "Congratulations!" << '\n';
        } else {
            cout << "What?" << '\n';
        }
    }

    return 0;
}