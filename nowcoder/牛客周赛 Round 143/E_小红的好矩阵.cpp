#include <bits/stdc++.h>
using namespace std;

int cal1(vector<string>& str, vector<string>& s) {
    int n = str[0].length();
    int ans = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j % 6] != str[i][j]) {
                ++ans;
            }
        }
    }
    return ans;
}

int cal3(const vector<string>& str, vector<string>& s) {
    int ans = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (str[i][j] != s[i][j]) {
                ++ans;
            }
        }
    }
    return ans;
}

int cal2(vector<string>& str, vector<vector<string>>& ss) {
    int ans = 0;
    int n = str[0].length();
    for (int i = 0; i < n; i += 3) {
        ans += min(cal3({str[0].substr(i, 3), str[1].substr(i, 3)}, ss[0]),
                   cal3({str[0].substr(i, 3), str[1].substr(i, 3)}, ss[1]));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> str(2);
    cin >> str[0] >> str[1];
    if (n % 3 != 0) {
        cout << -1 << '\n';
        return 0;
    }
    vector<vector<string>> ss = {{"000111", "111000"}, {"111000", "000111"}};
    int ans = INT_MAX;
    for (auto& s : ss) {
        ans = min(ans, cal1(str, s));
    }
    ss = {{"001", "011"}, {"011", "001"}};
    ans = min(ans, cal2(str, ss));
    ss = {{"110", "100"}, {"100", "110"}};
    ans = min(ans, cal2(str, ss));
    cout << ans << '\n';

    return 0;
}