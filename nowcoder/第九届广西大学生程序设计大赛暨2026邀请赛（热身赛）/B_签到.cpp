#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        string P;
        cin >> n >> P;
        int ans = -1;
        for (int i = 1; i <= n; ++i) {
            string S;
            cin >> S;
            if (S == P) {
                ans = i;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}