#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
int T, n, m, x, y;
int num[maxn];
int disl[maxn], disr[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
        }
        disl[1] = 0;
        disl[2] = 1;
        for (int i = 3; i <= n; ++i) {
            if (num[i] - num[i - 1] < num[i - 1] - num[i - 2]) {
                disl[i] = disl[i - 1] + 1;
            } else {
                disl[i] = disl[i - 1] + num[i] - num[i - 1];
            }
        }
        disr[n] = 0;
        disr[n - 1] = 1;
        for (int i = n - 2; i >= 1; --i) {
            if (num[i + 1] - num[i] < num[i + 2] - num[i + 1]) {
                disr[i] = disr[i + 1] + 1;
            } else {
                disr[i] = disr[i + 1] + num[i + 1] - num[i];
            }
        }
        cin >> m;
        while (m--) {
            cin >> x >> y;
            if (x < y) {
                cout << disl[y] - disl[x] << endl;
            } else {
                cout << disr[y] - disr[x] << endl;
            }
        }
    }

    return 0;
}
