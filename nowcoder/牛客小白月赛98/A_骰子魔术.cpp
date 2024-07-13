#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
int n, x, y;

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> y;
        if (y == x) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}
