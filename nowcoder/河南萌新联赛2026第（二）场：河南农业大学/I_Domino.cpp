#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int A;
        cin >> A;
        ans = max(ans, i + A - 1);
        if (ans == i) {
            break;
        }
    }
    cout << min(ans, n) << '\n';

    return 0;
}