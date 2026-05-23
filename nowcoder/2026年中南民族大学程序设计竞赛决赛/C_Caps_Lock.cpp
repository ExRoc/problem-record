#include <bits/stdc++.h>
using namespace std;

char change(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - 'a' + 'A';
    }
    return ch - 'A' + 'a';
}

int main() {
    ios::sync_with_stdio(false);

    int d;
    string s;
    cin >> d >> s;
    if (d == 0) {
        cout << s << '\n';
        return 0;
    }
    for (char ch : s) {
        cout << change(ch);
    }
    cout << '\n';

    return 0;
}