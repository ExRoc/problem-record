#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (char ch : s) {
        if (ch == '|') {
            ++ans;
        }
    }
    cout << ans / 2 << '\n';

    return 0;
}