#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
string str;

int main() {
    ios::sync_with_stdio(false);

    cin >> str;
    set<char> st(str.begin(), str.end());
    bool hasUppercase = false;
    bool hasLowercase = false;
    for (char ch : str) {
        if (ch >= 'a' && ch <= 'z') {
            hasLowercase = true;
        }
        if (ch >= 'A' && ch <= 'Z') {
            hasUppercase = true;
        }
    }
    if (hasLowercase && hasUppercase && st.size() == str.length()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
