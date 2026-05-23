#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int X;
    cin >> X;
    --X;
    string s = "HelloWorld";
    cout << s.substr(0, X) << s.substr(X + 1, s.length()) << '\n';

    return 0;
}