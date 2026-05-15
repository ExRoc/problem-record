#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    string str;
    cin >> str;
    int ans = 0;
    for (int i = 0; i < (int)str.length(); ++i) {
        if (str.substr(i, 4) == "SCMU") {
            ++ans;
        }
    }
    cout << ans << '\n';

    return 0;
}