#include <bits/stdc++.h>
using namespace std;

bool judge(int mx, int n, vector<long long> a) {
    while (a.size() < mx) {
        a.push_back(0);
    }
    for (int i = n; i >= mx; --i) {
        a[0] += a[i];
        a.pop_back();
    }
    const long long INF = 2e14;
    long long x = 1;
    for (int i = mx - 1; i > 0; --i) {
        if (x >= a[i]) {
            x = 2 * x - a[i];
        } else {
            a[0] += a[i] - x;
        }
        if (x > INF) {
            return false;
        }
    }
    return a[0] >= x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1);
        long long sum = 0;
        for (int i = 0; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum == 1) {
            for (int i = 0; i <= n; ++i) {
                if (a[i] == 1) {
                    cout << max(1, i) << '\n';
                    break;
                }
            }
            continue;
        }
        int low = 1;
        int high = n + 100;
        while (high - low > 1) {
            int mid = (high + low) >> 1;
            if (judge(mid, n, a)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        cout << low << '\n';
    }

    return 0;
}