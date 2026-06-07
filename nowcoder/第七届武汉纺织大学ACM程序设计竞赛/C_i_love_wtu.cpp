#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    string p = "ilovewtu";
    int n = p.length();
    int idx = 0;
    int ans = 0;
    for (char ch : S) {
        if (ch == p[idx]) {
            idx = (idx + 1) % n;
            if (idx == 0) {
                ++ans;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}