#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 10 + 100;
int T;
LL fenzi, fenmu;
LL a[maxn], b[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        fenmu = 0;
        for (int i = 0; i < 3; ++i) {
            cin >> a[i];
            fenmu += a[i];
        }
        for (int i = 0; i < 3; ++i) {
            cin >> b[i];
        }
        fenzi = 0;
        for (int i = 0; i < 3; ++i) {
            fenzi += b[i] * (a[(i + 2) % 3] - a[(i + 1) % 3]);
        }
        LL g = __gcd(fenzi, fenmu);
        fenzi /= g;
        fenmu /= g;
        if (fenzi == 0) {
            cout << 0 << endl;
            continue;
        }
        if (fenmu < 0) {
            fenmu = -fenmu;
            fenzi = -fenzi;
        }
        if (fenmu == 1) {
            cout << fenzi << endl;
            continue;
        }
        cout << fenzi << "/" << fenmu << endl;
    }

    return 0;
}
