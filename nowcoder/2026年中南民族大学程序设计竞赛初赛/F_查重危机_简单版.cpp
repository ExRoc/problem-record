#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    map<int, int> cnts;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        ++cnts[str.length()];
    }
    for (auto [len, cnt] : cnts) {
        if (len > 4) {
            continue;
        }
        if (pow(26, len) < cnt) {
            cout << "No" << '\n';
            return 0;
        }
    }
    cout << "Yes" << '\n';

    return 0;
}