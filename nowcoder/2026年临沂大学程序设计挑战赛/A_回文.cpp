#include <bits/stdc++.h>
using namespace std;

bool judge(const string& str) {
    int n = str.length();
    for (int i = 0; i < n; ++i) {
        if (str[i] != str[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string str;
    cin >> str;
    int idx1 = -1, idx2 = -1;
    for (int i = 0; i < n; ++i) {
        if (str[i] != str[n - i - 1]) {
            idx1 = i;
            idx2 = n - i - 1;
            break;
        }
    }
    if (idx1 == -1) {
        cout << "Yes" << '\n';
        return 0;
    }
    string tmp1 = str.substr(0, idx1) + str.substr(idx1 + 1, n);
    string tmp2 = str.substr(0, idx2) + str.substr(idx2 + 1, n);
    if (judge(tmp1) || judge(tmp2)) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }

    return 0;
}