#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    map<char, int> cnt;
    for (char ch : s) {
        if (ch >= '0' && ch <= '9') {
            ++cnt[ch];
        }
    }
    s = "";
    for (const auto& [key, value] : cnt) {
        for (int i = 0; i < value; ++i) {
            s += key;
        }
    }
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    if (s[0] == '0') {
        cout << 0 << '\n';
        return 0;
    }
    cout << s << '\n';

    return 0;
}