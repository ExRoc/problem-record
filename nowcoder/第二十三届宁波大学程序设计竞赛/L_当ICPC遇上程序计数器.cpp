#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.length();
    string tmp;
    int ans = 0;
    int idx = 0;
    while (idx < n) {
        tmp.push_back(s[idx]);
        int len = tmp.length();
        if (len >= 2 && tmp[len - 2] == 'I' && tmp[len - 1] == 'P') {
            s[idx - 1] = 'P';
            s[idx] = 'C';
            --idx;
            tmp.pop_back();
            tmp.pop_back();
            continue;
        }
        if (len >= 4 && tmp[len - 4] == 'I' && tmp[len - 3] == 'C' &&
            tmp[len - 2] == 'P' && tmp[len - 1] == 'C') {
            ++ans;
            tmp.pop_back();
            tmp.pop_back();
            tmp.pop_back();
            tmp.pop_back();
        }
        ++idx;
    }
    cout << ans << '\n';

    return 0;
}