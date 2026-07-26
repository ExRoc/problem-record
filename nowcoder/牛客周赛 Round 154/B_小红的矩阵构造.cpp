#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ' ';
    }
    cout << '\n';
    for (int i = n; i > 0; --i) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}