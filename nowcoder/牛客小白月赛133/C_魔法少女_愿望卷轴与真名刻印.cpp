#include <bits/stdc++.h>
using namespace std;

int cal(const string& S, int idx, const string& pattern) {
    int cnt = 0;
    for (int i = 0; i < (int)pattern.size(); ++i) {
        if (pattern[i] != S[idx + i]) {
            ++cnt;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        string S;
        cin >> S;
        if (k >= 17) {
            cout << "Yes" << '\n';
            continue;
        }
        vector<vector<int>> awdec(6), Fantasy_Blue(13);
        for (int i = 0; i < n; ++i) {
            if (i + 5 <= n) {
                awdec[cal(S, i, "awdec")].push_back(i);
            }
            if (i + 12 <= n) {
                Fantasy_Blue[cal(S, i, "Fantasy_Blue")].push_back(i);
            }
        }
        bool flag = false;
        for (int i = 0; i <= k && i <= 5; ++i) {
            for (int idx1 : awdec[i]) {
                for (int j = 0; i + j <= k && j <= 12; ++j) {
                    for (int idx2 : Fantasy_Blue[j]) {
                        if (idx1 + 5 <= idx2 || idx2 + 12 <= idx1) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag) {
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        if (flag) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }

    return 0;
}