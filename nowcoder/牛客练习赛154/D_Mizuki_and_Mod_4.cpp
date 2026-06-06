#include <bits/stdc++.h>
using namespace std;

int toNum(char ch) { return ch - '0'; }

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        int n = S.length();
        if (n == 1) {
            cout << (toNum(S[0]) % 4 == 0 ? "YES" : "NO") << '\n';
            continue;
        }
        if ((toNum(S[n - 2]) * 10 + toNum(S[n - 1])) % 4 == 0) {
            cout << "YES" << '\n';
            continue;
        }
        stack<char> sta;
        sta.push(S[n - 1]);
        bool flag = false;
        bool ans = false;
        for (int i = n - 2; i >= 0; --i) {
            if (!flag) {
                if ((toNum(S[i]) * 10 + toNum(sta.top())) % 4 == 0) {
                    flag = true;
                    sta.pop();
                    if (sta.empty()) {
                        ans = true;
                        break;
                    }
                } else {
                    if (i > 0 &&
                        (toNum(S[i - 1]) * 10 + toNum(S[i])) % 4 == 0) {
                        sta.push(S[i]);
                    } else {
                        if (toNum(S[i]) % 4 == 0) {
                            continue;
                        } else {
                            sta.push(S[i]);
                        }
                    }
                }
            } else {
                if ((toNum(S[i]) * 10 + toNum(sta.top())) % 4 == 0) {
                    sta.pop();
                    if (sta.empty()) {
                        ans = true;
                        break;
                    }
                }
            }
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}