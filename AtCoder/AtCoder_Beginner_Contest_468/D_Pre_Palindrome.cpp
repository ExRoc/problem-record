#include <bits/stdc++.h>
using namespace std;

int id(int a, int b, int c, int n) { return a * n * 2 + b * 2 + c; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int n = S.length();
    vector<bool> dp(n * n * 2, false);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        dp[id(i, i, 0, n)] = true;
        ++ans;
    }
    for (int i = 1; i < n; ++i) {
        if (S[i - 1] == S[i]) {
            dp[id(i - 1, i, 0, n)] = true;
            ++ans;
        } else {
            dp[id(i - 1, i, 1, n)] = true;
            ++ans;
        }
    }
    for (int len = 3; len <= n; ++len) {
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1;
            if (S[l] == S[r]) {
                if (dp[id(l + 1, r - 1, 0, n)]) {
                    dp[id(l, r, 0, n)] = true;
                    ++ans;
                } else if (dp[id(l + 1, r - 1, 1, n)]) {
                    dp[id(l, r, 1, n)] = true;
                    ++ans;
                }
            } else {
                if (dp[id(l + 1, r - 1, 0, n)]) {
                    dp[id(l, r, 1, n)] = true;
                    ++ans;
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}