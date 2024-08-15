#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int n, m;
int num[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
        if (m >= num[i]) {
            m -= num[i];
        } else {
            cout << i - 1 << endl;
            return 0;
        }
    }
    cout << n << endl;

    return 0;
}
