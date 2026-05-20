#include <bits/stdc++.h>
using namespace std;

char toUpper(char ch) { return ch - 'a' + 'A'; }

int main() {
    ios::sync_with_stdio(false);

    string str;
    getline(cin, str);
    if (str.length() == 0) {
        return 0;
    }
    str[0] = toUpper(str[0]);
    for (int i = 1; i < str.length(); ++i) {
        if (str[i - 1] == ' ') {
            str[i] = toUpper(str[i]);
        }
    }
    cout << str << '\n';

    return 0;
}