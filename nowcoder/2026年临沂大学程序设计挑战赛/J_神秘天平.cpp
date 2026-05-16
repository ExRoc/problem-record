#include <bits/stdc++.h>
using namespace std;

bool dfs(int depth, const string& p, const vector<string>& ss,
         const vector<int>& vs, string& ans, vector<int>& mp) {
    if (depth == 5) {
        for (int i = 0; i < (int)ss.size(); ++i) {
            int sum = 0;
            for (char ch : ss[i]) {
                sum += mp[ch - 'A'];
            }
            if (sum != vs[i]) {
                return false;
            }
        }
        string tmp;
        for (char ch : p) {
            tmp.push_back('0' + mp[ch - 'A']);
        }
        ans = min(ans, tmp);
        return true;
    }
    bool flag = false;
    for (int i = 0; i < 10; ++i) {
        mp[depth] = i;
        bool res = dfs(depth + 1, p, ss, vs, ans, mp);
        flag = (flag || res);
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(false);

    int m;
    cin >> m;
    vector<string> ss(m);
    vector<int> vs(m);
    for (int i = 0; i < m; ++i) {
        cin >> ss[i] >> vs[i];
    }
    string p;
    cin >> p;
    string ans;
    vector<int> mp(5);
    for (int i = 0; i < (int)p.length(); ++i) {
        ans.push_back('9');
    }
    if (!dfs(0, p, ss, vs, ans, mp)) {
        cout << "Impossible" << '\n';
    } else {
        cout << ans << '\n';
    }

    return 0;
}