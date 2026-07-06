#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> solve(const string& S, const string& pattern) {
    int n = S.length();
    set<pair<int, int>> st;
    for (int i = 0; i < n; ++i) {
        int idx = 0;
        for (int j = i; j < n; ++j) {
            if (idx < 4 && S[j] == pattern[idx]) {
                ++idx;
            }
            if (idx == 4) {
                st.insert(make_pair(i, j));
            }
        }
    }
    return st;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    vector<string> ss = {"whut", "wuht", "wuth"};
    int n = S.length();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> idx(3, 0);
        for (int j = i; j < n; ++j) {
            bool flag = false;
            for (int k = 0; k < 3; ++k) {
                if (idx[k] < 4 && S[j] == ss[k][idx[k]]) {
                    ++idx[k];
                }
                if (idx[k] == 4) {
                    flag = true;
                }
            }
            if (flag) {
                ++ans;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}