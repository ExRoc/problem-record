#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int ans = 100;
    for (int i = 0; i < n; ++i) {
        ans = ans * 0.9;
    }
    cout << ans << '\n';

    return 0;
}