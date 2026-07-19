#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string A, B;
    cin >> A >> B;
    int sum = 0, mx = 0;
    for (int x = -5000; x <= 5000; ++x) {
        int mxTmp = 0;
        for (int i = 0; i < m; ++i) {
            if (i + x >= 0 && i + x < n && A[i + x] == B[i]) {
                ++sum;
                ++mxTmp;
            }
        }
        mx = max(mxTmp, mx);
    }
    cout << mx << '\n' << sum << '\n';

    return 0;
}