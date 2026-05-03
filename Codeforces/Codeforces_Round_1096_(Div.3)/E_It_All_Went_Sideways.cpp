#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T, n;
    vector<long long> num;
    cin >> T;
    vector<int> sta;
    while (T--) {
        cin >> n;
        num.assign(n + 1, 0);
        while (!sta.empty()) {
            sta.pop_back();
        }
        sta.push_back(0);
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
        }
        long long mn = num[n];
        long long tmp = 0;
        for (int i = n; i > 0; --i) {
            tmp += max(num[i] - mn, 0LL);
            mn = min(mn, num[i]);
        }
        long long ans = tmp;
        for (int i = 1; i <= n; ++i) {
            while (num[sta.back()] >= num[i]) {
                sta.pop_back();
            }
            ans = max(ans, (long long)i - sta.back() + tmp - 1);
            sta.push_back(i);
        }
        cout << ans << endl;
    }

    return 0;
}
