#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> cal(char s, long long c) {
    if (s == 'S') {
        return {c / 4, c / 4};
    }
    if (s == 'D') {
        return {c / 6, c / 3};
    }
    if (s == 'R') {
        return {c / 5, 3 * c / 10};
    }
    return {3 * c / 14, 2 * c / 7};
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        map<char, pair<int, pair<long long, long long>>> mp;
        for (int i = 1; i <= m; ++i) {
            char s;
            long long c;
            cin >> s >> c;
            pair<long long, long long> pTmp = cal(s, c);
            if (mp.find(s) == mp.end()) {
                mp[s] = {i, pTmp};
            }
        }
        bool flag = true;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            char s;
            long long c;
            cin >> s >> c;
            pair<long long, long long> pTmp = cal(s, c);
            bool f = false;
            for (auto [ss, pp] : mp) {
                if (pp.second.first >= pTmp.first &&
                    pp.second.first >= pTmp.second) {
                    f = true;
                    ans.push_back(pp.first);
                    break;
                }
            }
            if (!f) {
                flag = false;
            }
        }
        if (!flag) {
            cout << -1 << '\n';
        } else {
            for (int x : ans) {
                cout << x << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}