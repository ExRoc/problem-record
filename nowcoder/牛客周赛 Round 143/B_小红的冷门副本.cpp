#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, m, x;
    cin >> n >> m >> x;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++cnt[a];
    }
    int ans = m;
    for (auto [_, cnt] : cnt) {
        if (cnt > x) {
            --ans;
        }
    }
    cout << ans << '\n';

    return 0;
}