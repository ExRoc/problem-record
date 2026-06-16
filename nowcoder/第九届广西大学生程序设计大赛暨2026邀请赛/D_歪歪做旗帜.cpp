#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<char, int> cnt;
        for (char ch : s) {
            ++cnt[ch];
        }
        cout << min({cnt['G'], cnt['X'], cnt['C'] / 2, cnt['P']}) << '\n';
    }

    return 0;
}