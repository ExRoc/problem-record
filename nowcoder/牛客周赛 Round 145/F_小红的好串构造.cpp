#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int sum = 2 * n - 3;
        for (int i = 0; i < sum - k; ++i) {
            cout << 'a';
        }
        cout << "bc";
        for (int i = 0; i < n - (sum - k) - 2; ++i) {
            cout << 'b';
        }
        cout << '\n';
    }

    return 0;
}