#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<long long> a(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    vector<long long> aTmp = a;
    long long mn = 0;
    for (int i = 1; i <= n; ++i) {
        int mnIdx = -1;
        for (int j = 1; j <= m; ++j) {
            if (a[j] == 0) {
                continue;
            }
            if (mnIdx == -1 || a[j] < a[mnIdx]) {
                mnIdx = j;
            }
        }
        mn += a[mnIdx];
        --a[mnIdx];
    }
    a = aTmp;
    long long mx = 0;
    for (int i = 1; i <= n; ++i) {
        int mxIdx = -1;
        for (int j = 1; j <= m; ++j) {
            if (a[j] == 0) {
                continue;
            }
            if (mxIdx == -1 || a[j] > a[mxIdx]) {
                mxIdx = j;
            }
        }
        mx += a[mxIdx];
        --a[mxIdx];
    }
    cout << mx << ' ' << mn << '\n';

    return 0;
}