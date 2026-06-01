#include <bits/stdc++.h>
using namespace std;

bool judge(int x, const vector<int>& a, const vector<int>& b, int n) {
    int pre = -1;
    vector<int> cnt(2, 0);
    for (int i = 0; i < n; ++i) {
        int tmp = (a[i] >= x) + (b[i] >= x);
        if (tmp == 0) {
            if (pre != 0) {
                ++cnt[0];
            }
            pre = tmp;
        } else if (tmp == 2) {
            ++cnt[1];
            pre = tmp;
        }
    }
    return cnt[1] > cnt[0];
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        int high = 2 * n + 1;
        int low = 1;
        while (high - low > 1) {
            int mid = (high + low) >> 1;
            if (judge(mid, a, b, n)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        cout << low << '\n';
    }

    return 0;
}