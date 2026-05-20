#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int d = (k + n - 3) / (n - 1);
        int x = 1;
        for (int i = 0; i < n; ++i) {
            cout << x << " ";
            x = min(x + d, k);
        }
        cout << '\n';
    }

    return 0;
}