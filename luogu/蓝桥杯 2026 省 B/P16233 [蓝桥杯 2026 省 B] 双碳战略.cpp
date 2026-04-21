#include <bits/stdc++.h>
using namespace std;

string bit(int x, int dig) {
    string ret;
    for (int i = dig - 1; i >= 0; --i) {
        ret += ('0' + ((x >> i) & 1));
    }
    return ret;
}

void solve(int len) {
    queue<pair<int, int>> que;
    que.push({0, 0});
    set<int> st;
    st.insert(0);
    int top = (1 << len) - 1;
    while (!que.empty()) {
        pair<int, int> tmp = que.front();
        que.pop();
        cout << bit(tmp.first, len) << " " << tmp.second << '\n';
        for (int i = 0; i < len; ++i) {
            int xorTmp = top;
            if (tmp.second % 2 == 0) {
                xorTmp >>= i;
            } else {
                xorTmp <<= i;
                xorTmp &= top;
            }
            pair<int, int> pos = {tmp.first ^ xorTmp, tmp.second + 1};
            if (st.find(pos.first) == st.end()) {
                st.insert(pos.first);
                que.push(pos);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    // for (int len = 1; len <= 5; ++len) {
    //     solve(len);
    // }
    const int n = 2026;
    const long long MOD = 998244353;
    vector<vector<long long>> C =
        vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans += i * C[n][i] % MOD;
        ans %= MOD;
    }
    cout << ans << '\n';

    return 0;
}
