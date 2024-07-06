#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 250000 + 100;
int T, b, c, h;

int main() {
    cin >> T;
    while (T--) {
        cin >> b >> c >> h;
        cout << min(b - 1, c + h) * 2 + 1 << endl;
    }

    return 0;
}
