#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200 + 100;
int n;
LL sum, mn;
LL num[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    mn = 1e10;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> num[i][j];
            sum += num[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        mn = min(mn, num[i][n - i - 1]);
    }
    cout << sum - mn << endl;

    return 0;
}
