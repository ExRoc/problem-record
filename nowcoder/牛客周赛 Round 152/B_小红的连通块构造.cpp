#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    vector<string> ans(7);
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 6; ++j) {
            char tmp = (i + j) % 2 + '0';
            if (tmp == '1') {
                if (k > 0) {
                    --k;
                } else {
                    tmp = '0';
                }
            }
            ans[i].push_back(tmp);
        }
    }
    if (k != 0) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < 7; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}