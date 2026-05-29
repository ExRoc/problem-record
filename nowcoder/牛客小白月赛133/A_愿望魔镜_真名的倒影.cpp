#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    if (S == "awdec") {
        cout << "Fantasy_Blue" << '\n';
    } else if (S == "Fantasy_Blue") {
        cout << "awdec" << '\n';
    } else {
        cout << "other" << '\n';
    }

    return 0;
}