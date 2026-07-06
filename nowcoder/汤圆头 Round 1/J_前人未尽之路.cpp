#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const long long e9 = 1000000000;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<long long, long long>> range(n + 1);
        for (int i = 0; i <= n; ++i) {
            range[i].first = i;
            range[i].second = i * e9;
        }
        vector<long long> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        vector<int> c(m);
        for (int i = 0; i < m; ++i) {
            cin >> c[i];
        }

        for (int i = 0; i < m; ++i) {
            range[c[i]].second = min(range[c[i]].second, b[i]);
            if (c[i] + 1 <= n) {
                range[c[i] + 1].first = max(range[c[i] + 1].first, b[i] + 1);
            }
        }
        for (int i = n - 1; i >= 1; --i) {
            range[i].second = min(range[i].second, range[i + 1].second - 1);
        }
        bool valid = true;
        for (int i = 1; i <= n; ++i) {
            if (range[i].second < range[i].first) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            cout << -1 << '\n';
            continue;
        }
        vector<long long> sum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            sum[i] = min(sum[i - 1] + e9, range[i].second);
            if (sum[i] < range[i].first || sum[i] > range[i].second ||
                sum[i] - sum[i - 1] <= 0 || sum[i] - sum[i - 1] > e9) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = 0; i < m; ++i) {
            if (upper_bound(sum.begin(), sum.end(), b[i]) - sum.begin() !=
                c[i] + 1) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = 1; i <= n; ++i) {
            cout << sum[i] - sum[i - 1] << " ";
        }
        cout << '\n';
    }

    return 0;
}