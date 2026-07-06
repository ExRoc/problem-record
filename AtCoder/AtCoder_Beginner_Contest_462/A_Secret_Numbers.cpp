#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    for (char ch : S) {
        if (ch >= '0' && ch <= '9') {
            cout << ch;
        }
    }
    cout << '\n';

    return 0;
}