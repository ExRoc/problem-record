#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    int idx = n + 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] != 1) {
            idx = i;
            break;
        }
    }
    cout << (idx % 2 == 1 ? "Elma" : "Amy") << '\n';

    return 0;
}