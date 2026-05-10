#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n * 2; ++i) {
            int x;
            cin >> x;
        }
        for (int i = 2; i <= n; ++i) {
            cout << "1 " << i << '\n';
        }
    }

    return 0;
}