#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int maxn = 10000000 + 100;
    vector<int> ans(maxn);
    ans[1] = 2;
    ans[2] = 3;
    for (int i = 2; i < maxn - 10; ++i) {
        if (ans[i] == 0) {
            if (ans[i + 2] != 0 && ans[i + 2] == ans[i - 1] + 3) {
                ans[i] = ans[i - 1] + 1;
            }
            if (ans[i + 1] != 0 && ans[i + 1] == ans[i - 1] + 2) {
                ans[i] = ans[i - 1] + 1;
            }
        }
        if (ans[i] < maxn) {
            ans[ans[i]] = 3 * i;
        }
    }
    int N;
    cin >> N;
    cout << ans[N] << '\n';

    return 0;
}