#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    vector<int> cnt(2, 0);
    vector<long long> sum(2, 0);
    for (int i = 0; i < n; ++i) {
        ++cnt[s[i] - '0'];
        sum[s[i] - '0'] += a[i];
    }
    long long ss = sum[0] + sum[1];
    if (ss * cnt[0] % (cnt[0] + cnt[1]) != 0 ||
        ss * cnt[1] % (cnt[0] + cnt[1]) != 0) {
        cout << -1 << '\n';
        return 0;
    }
    long long sss = ss * cnt[0] / (cnt[0] + cnt[1]);
    cout << abs(sss - sum[0]) << '\n';

    return 0;
}