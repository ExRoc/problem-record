#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    if ((int)s.length() == 1 || (int)t.length() == 1) {
        cout << -1 << '\n';
        return 0;
    }
    string p = "WSAD";
    sort(p.begin(), p.end());
    do {
        string ans;
        for (int i = 0; i < n; ++i) {
            ans += p;
        }
        if (ans.find(s) == string::npos && ans.find(t) == string::npos) {
            cout << ans << '\n';
            return 0;
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << -1 << '\n';

    return 0;
}