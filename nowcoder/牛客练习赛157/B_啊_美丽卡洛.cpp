#include <bits/stdc++.h>
using namespace std;

bool judge(const vector<long long>& a, int n, long long k) {
    long long last = a[0] - k;
    for (int i = 1; i < n; ++i) {
        last = max(a[i] - k, last + 1);
        if (last < a[i] - k || last > a[i] + k) {
            return false;
        }
    }
    return true;
}

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        long long high = n;
        long long low = -1;
        while (high - low > 1) {
            long long mid = (high + low) >> 1;
            if (judge(a, n, mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        cout << high << '\n';
    }

    return 0;
}