#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
string str;
int cnt0, cnt1;

char toLower(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch;
    }
    return ch - 'A' + 'a';
}

char toUpper(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch;
    }
    return ch - 'a' + 'A';
}

int main() {
    ios::sync_with_stdio(false);

    cin >> str;
    for (char ch : str) {
        if (ch >= 'a' && ch <= 'z') {
            ++cnt0;
        } else {
            ++cnt1;
        }
    }
    int n = str.length();
    for (int i = 0; i < n; ++i) {
        if (cnt0 > cnt1) {
            cout << toLower(str[i]);
        } else {
            cout << toUpper(str[i]);
        }
    }
    cout << endl;

    return 0;
}
