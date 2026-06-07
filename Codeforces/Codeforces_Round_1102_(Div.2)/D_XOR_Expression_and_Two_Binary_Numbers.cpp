#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s, z;
        cin >> s >> z;
        string t;
        for (int i = 0; i < n; ++i) {
            if (s[i] == z[i]) {
                t.push_back('0');
            } else {
                t.push_back('1');
            }
        }
        vector<long long> cnts(2, 0), cntz(2, 0), cntt(2, 0);
        for (int i = 0; i < n; ++i) {
            ++cnts[s[i] - '0'];
            ++cntz[z[i] - '0'];
            ++cntt[t[i] - '0'];
        }
        long long tmp = 1;
        for (int i = 2; i <= k; ++i) {
            if (i % 2 == 0) {
                tmp *= 2;
            } else {
                tmp = tmp * 2 - 1;
            }
        }
        long long ans =
            tmp * (cnts[0] * cnts[1] + cntz[0] * cntz[1] + cntt[0] * cntt[1]);
        if (k % 2 == 0) {
            ans -= cntt[0] * cntt[1];
        }
        cout << ans << '\n';
    }

    return 0;
}