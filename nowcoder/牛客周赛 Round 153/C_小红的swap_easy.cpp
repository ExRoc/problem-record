#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    if (s == t) {
        cout << 0 << '\n';
        return 0;
    }
    vector<vector<int>> idxs(2);
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            idxs[s[i] - '0'].push_back(i + 1);
        }
    }
    cout << idxs[0].size() + idxs[1].size() + 1 << '\n';
    for (int i = 0; i < idxs[0].size(); ++i) {
        cout << idxs[0][i] << '\n' << idxs[1][i] << '\n';
    }
    cout << idxs[0][0] << '\n';

    return 0;
}