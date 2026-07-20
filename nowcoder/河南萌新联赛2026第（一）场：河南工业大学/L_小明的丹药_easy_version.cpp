#include <bits/stdc++.h>
using namespace std;

bool judge(int a, int b, int c) {
    if (c % 2 == 1) {
        if (b == 0) {
            return false;
        }
        c -= min(c / 2 * 2, a * 2);
        return c <= b;
    }
    c -= min(c / 2 * 2, a * 2);
    return c <= b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = 0;
        int top = min(2 * a + b, 2 * c + d);
        for (int i = 0; i <= top; ++i) {
            if (judge(a, b, i) && judge(c, d, i)) {
                ans = i;
            }
        }
        cout << ans * 2 << '\n';
    }

    return 0;
}