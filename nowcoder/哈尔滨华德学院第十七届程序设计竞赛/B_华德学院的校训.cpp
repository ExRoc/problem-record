#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    string str;
    getline(cin, str);
    while (T--) {
        string str;
        getline(cin, str);
        if (str == "chengyi qiuzhen duxue qiangji") {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}