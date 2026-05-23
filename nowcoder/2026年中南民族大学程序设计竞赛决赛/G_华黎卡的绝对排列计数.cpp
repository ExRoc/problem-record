#include <bits/stdc++.h>
using namespace std;

bool judge(int r, int l, int n, const vector<int>& sum) {
    int suml = sum[l] - sum[l - 1];
    int sumr = sum[r] - sum[l - 1];
    int d = sumr - suml;
    return abs(abs(sumr) - abs(suml)) == r - l;
}

int solve(int idx, int n, const vector<int>& sum) {
    int low = idx;
    int high = n + 1;
    int mid;
    while (high - low > 1) {
        mid = (high + low) >> 1;
        if (judge(mid, idx, n, sum)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == 0) {
                ans += solve(i, n, sum) - i + 1;
                continue;
            }
            if (i == n) {
                continue;
            }
            if (a[i] + a[i + 1] == 0) {
                ans += solve(i, n, sum) - i;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}