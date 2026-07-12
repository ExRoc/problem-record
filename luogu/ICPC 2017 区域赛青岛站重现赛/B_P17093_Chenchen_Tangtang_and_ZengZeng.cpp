#include <bits/stdc++.h>
using namespace std;

bool judge(const vector<string>& s, char ch) {
    for (int i = 0; i < 3; ++i) {
        bool flag = true;
        for (int j = 0; j < 3; ++j) {
            if (s[i][j] != ch) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return true;
        }
    }
    for (int j = 0; j < 3; ++j) {
        bool flag = true;
        for (int i = 0; i < 3; ++i) {
            if (s[i][j] != ch) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return true;
        }
    }
    bool flag = true;
    for (int i = 0; i < 3; ++i) {
        if (s[i][i] != ch) {
            flag = false;
            break;
        }
    }
    if (flag) {
        return true;
    }
    flag = true;
    for (int i = 0; i < 3; ++i) {
        if (s[i][2 - i] != ch) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        vector<string> s(3);
        for (int i = 0; i < 3; ++i) {
            cin >> s[i];
        }
        string CTZ = "CTZ";
        bool flag = false;
        for (int i = 0; i < 3; ++i) {
            if (judge(s, CTZ[i])) {
                cout << CTZ[i] << '\n';
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "ongoing" << '\n';
        }
    }

    return 0;
}