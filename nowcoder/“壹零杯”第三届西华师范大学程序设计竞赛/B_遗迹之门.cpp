#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        if (S.find("CWNU") != string::npos) {
            cout << "SAFE" << '\n';
        } else {
            cout << "TRAP" << '\n';
        }
    }

    return 0;
}