#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, int> cntx, cnty;
        for (int i = 0; i < n; ++i) {
            int x, y, r;
            cin >> x >> y >> r;
            ++cntx[x - r];
            ++cntx[x + r];
            ++cnty[y - r];
            ++cnty[y + r];
        }
        int ans = 0;
        for (map<int, int>::iterator it = cntx.begin(); it != cntx.end();
             ++it) {
            ans = max(ans, it->second);
        }
        for (map<int, int>::iterator it = cnty.begin(); it != cnty.end();
             ++it) {
            ans = max(ans, it->second);
        }
        cout << ans << '\n';
    }

    return 0;
}