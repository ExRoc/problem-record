#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        vector<int> cnt(27, 0);
        for (char ch : S) {
            ++cnt[ch - 'a'];
        }
        int last = 26;
        string ans;
        bool flag = true;
        for (int i = 0; i < (int)S.length(); ++i) {
            int mxIdx = 26;
            for (int j = 0; j < 26; ++j) {
                if (j == last) {
                    continue;
                }
                if (cnt[mxIdx] < cnt[j]) {
                    mxIdx = j;
                }
            }
            if (cnt[mxIdx] == 0) {
                flag = false;
                break;
            }
            last = mxIdx;
            ans += (char)('a' + mxIdx);
            --cnt[mxIdx];
        }
        if (!flag) {
            cout << "No" << '\n';
            continue;
        }
        for (int i = 1; i < (int)S.length(); ++i) {
            if (ans[i] == ans[i - 1]) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            cout << "No2" << '\n';
            continue;
        }
        cout << "Yes" << '\n';
        cout << ans << '\n';
    }

    return 0;
}