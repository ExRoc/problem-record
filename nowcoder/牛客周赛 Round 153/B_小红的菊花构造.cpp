#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        if (i == k) {
            continue;
        }
        cout << i << ' ' << k << '\n';
    }

    return 0;
}