#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 500000 + 100;
int n;
LL dsum;
LL num[maxn], d[maxn], ans[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
        dsum += d[i];
        num[i] += dsum;
        LL dd = min(num[i], (LL)(n - i));
        ++d[i + 1];
        --d[i + dd + 1];
        num[i] -= dd;
        // for (int i = 1; i <= n + 1; ++i) {
        //     cout << d[i] << " ";
        // }
        // cout << endl;
    }
    for (int i = 1; i <= n; ++i) {
        cout << num[i] << " ";
    }
    cout << endl;

    return 0;
}
