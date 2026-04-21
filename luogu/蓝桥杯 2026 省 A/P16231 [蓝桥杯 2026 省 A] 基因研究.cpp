#include <bits/stdc++.h>
using namespace std;

vector<int> buildPrefix(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0;
    for (int i = 1; i < m;) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int main() {
    ios::sync_with_stdio(false);

    string AGCT = "ATGC";
    map<char, int> mp;
    for (int i = 0; i < 4; ++i) {
        mp[AGCT[i]] = i;
    }

    int n, m;
    cin >> n >> m;
    string pattern;
    cin >> pattern;
    vector<int> lps = buildPrefix(pattern);
    pattern = "$" + pattern;
    lps.insert(lps.begin(), 0);

    vector<vector<int>> tree = vector<vector<int>>(m + 1, vector<int>(4, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (mp[pattern[i]] == j) {
                tree[i - 1][j] = i;
            } else {
                tree[i - 1][j] = tree[lps[i - 1]][j];
            }
        }
    }
    tree[m] = vector<int>(4, m);

    vector<vector<long long>> dp =
        vector<vector<long long>>(n + 1, vector<long long>(m + 1, 0));
    dp[0][0] = 1;
    const long long MOD = 998244353;
    long long p;
    for (int i = 1; i <= n; ++i) {
        for (int k = 0; k < 4; ++k) {
            cin >> p;
            for (int j = 0; j <= m; ++j) {
                int nextJ = tree[j][k];
                dp[i][nextJ] += dp[i - 1][j] * p % MOD;
                dp[i][nextJ] %= MOD;
            }
        }
    }
    cout << dp[n][m] << '\n';

    return 0;
}
