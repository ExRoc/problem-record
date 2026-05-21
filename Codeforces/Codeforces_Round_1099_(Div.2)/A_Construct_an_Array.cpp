#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= 2 * n; i += 2) {
            cout << i << " ";
        }
        cout << '\n';
    }

    return 0;
}