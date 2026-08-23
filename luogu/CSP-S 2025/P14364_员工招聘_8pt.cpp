#include <bits/stdc++.h>
using namespace std;

int solve(int m, const string& s, const vector<int>& c,
          const vector<int>& idx) {
    int ans = 0;
    int cTmp = 0;
    for (int i = 0; i < (int)s.length(); ++i) {
        if (s[i] == '0') {
            ++cTmp;
        } else {
            if (cTmp < c[idx[i]]) {
                ++ans;
            } else {
                ++cTmp;
            }
        }
    }
    return ans >= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> c(n);
    vector<int> idx(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        idx[i] = i;
    }
    int ans = 0;
    do {
        ans += solve(m, s, c, idx);
    } while (next_permutation(idx.begin(), idx.end()));
    cout << ans << '\n';

    return 0;
}