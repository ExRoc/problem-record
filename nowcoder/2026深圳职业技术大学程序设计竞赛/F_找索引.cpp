#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    while (q--) {
        int x;
        cin >> x;
        int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
        if (idx == n || a[idx] != x) {
            cout << -1 << '\n';
        } else {
            cout << idx + 1 << '\n';
        }
    }

    return 0;
}