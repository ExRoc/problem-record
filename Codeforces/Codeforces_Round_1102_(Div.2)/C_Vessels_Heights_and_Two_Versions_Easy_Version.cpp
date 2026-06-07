#include <bits/stdc++.h>
using namespace std;

long long solve(int idx, int n, const vector<long long>& h) {
    vector<long long> w(n);
    w[idx] = 0;
    long long last = 0;
    for (int i = 1; i < n; ++i) {
        int idxTmp = (idx + i) % n;
        w[idxTmp] = max(last, h[(idxTmp - 1 + n) % n]);
        last = w[idxTmp];
    }
    last = 0;
    long long ans = 0;
    for (int i = 1; i < n; ++i) {
        int idxTmp = (idx - i + n) % n;
        long long wTmp = max(last, h[idxTmp]);
        last = wTmp;
        ans += min(w[idxTmp], wTmp);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> h(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        for (int i = 0; i < n; ++i) {
            cout << solve(i, n, h) << " ";
        }
        cout << '\n';
    }

    return 0;
}