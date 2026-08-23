#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n * m);
    for (int i = 0; i < n * m; ++i) {
        cin >> a[i];
    }
    int A = a[0];
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int idx = -1;
    for (int i = 0; i < n * m; ++i) {
        if (a[i] == A) {
            idx = i + 1;
            break;
        }
    }
    int c = (idx + n - 1) / n;
    int r = idx % n;
    if (r == 0) {
        r = n;
    }
    if (c % 2 == 0) {
        r = n + 1 - r;
    }
    cout << c << ' ' << r << '\n';

    return 0;
}