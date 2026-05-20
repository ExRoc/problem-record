#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    string str;
    cin >> n >> str;
    map<char, int> cnt;
    for (char ch : str) {
        ++cnt[ch];
    }
    for (char ch = 'A'; ch <= 'D'; ++ch) {
        if (cnt[ch] != cnt['A']) {
            cout << "No" << '\n';
            return 0;
        }
    }
    cout << "Yes" << '\n';

    return 0;
}