#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    cout << s.substr(0, 3) << "-" << s.substr(3, 4) << "-" << s.substr(7, 4)
         << '\n';

    return 0;
}