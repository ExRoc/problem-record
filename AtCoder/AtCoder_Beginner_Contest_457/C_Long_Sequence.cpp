#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    long long k;
    cin >> n >> k;
    vector<vector<int>> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        int l;
        cin >> l;
        a[i].assign(l + 1, 0);
        for (int j = 1; j <= l; ++j) {
            cin >> a[i][j];
        }
    }
    vector<long long> c(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; ++i) {
        long long l = a[i].size() - 1;
        if (k <= c[i] * l) {
            k %= l;
            if (k == 0) {
                cout << a[i].back() << '\n';
            } else {
                cout << a[i][k] << '\n';
            }
            return 0;
        }
        k -= c[i] * l;
    }

    return 0;
}