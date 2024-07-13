#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
int n, x;
int cnt[2];

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        ++cnt[x & 1];
    }
    if (cnt[1] >= cnt[0]) {
        cout << ((cnt[1] - cnt[0]) & 1) << endl;
        return 0;
    }
    cout << cnt[0] - cnt[1] << endl;

    return 0;
}
