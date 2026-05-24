#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            if (b[i] < a[i]) {
                swap(a[i], b[i]);
            }
        }
        int mx = 1;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += b[i];
            mx = max(mx, a[i]);
        }
        cout << sum + mx << '\n';
    }

    return 0;
}