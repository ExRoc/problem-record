#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    cout << n * m << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << j;
        }
    }
    cout << endl;

    return 0;
}