#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        if (k == 0) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }
    sort(a.begin(), a.end());
    int last = a[1] + k;
    int ans = 2;
    for (int i = 2; i < n; ++i) {
        if (a[i] > last + 1) {
            ans += k + 1;
            last = a[i] + k;
        } else {
            ans += a[i] + k - last;
            last = a[i] + k;
        }
    }
    cout << ans << endl;

    return 0;
}