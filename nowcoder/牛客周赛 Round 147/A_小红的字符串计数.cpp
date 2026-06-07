#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (char ch : s) {
        ++cnt[ch - 'a'];
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] == 1) {
            ++ans;
        }
    }
    cout << ans << '\n';

    return 0;
}