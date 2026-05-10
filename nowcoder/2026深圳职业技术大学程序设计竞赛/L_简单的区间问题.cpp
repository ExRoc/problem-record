#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> num(n + 2);
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
        }
        const int INF = 1e9;
        num[0] = num[n + 1] = INF;
        vector<int> sta;
        vector<int> l(n + 1);
        sta.push_back(0);
        for (int i = 1; i <= n; ++i) {
            while (num[sta.back()] <= num[i]) {
                sta.pop_back();
            }
            l[i] = i - sta.back();
            sta.push_back(i);
        }
        vector<int> r(n + 1);
        sta.clear();
        sta.push_back(n + 1);
        for (int i = n; i >= 1; --i) {
            while (num[sta.back()] < num[i]) {
                sta.pop_back();
            }
            r[i] = sta.back() - i;
            sta.push_back(i);
        }
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += 1LL * num[i] * l[i] * r[i];
        }
        num[0] = num[n + 1] = 0;
        sta.clear();
        sta.push_back(0);
        for (int i = 1; i <= n; ++i) {
            while (num[sta.back()] >= num[i]) {
                sta.pop_back();
            }
            l[i] = i - sta.back();
            sta.push_back(i);
        }
        sta.clear();
        sta.push_back(n + 1);
        for (int i = n; i >= 1; --i) {
            while (num[sta.back()] > num[i]) {
                sta.pop_back();
            }
            r[i] = sta.back() - i;
            sta.push_back(i);
        }
        for (int i = 1; i <= n; ++i) {
            ans += 1LL * num[i] * l[i] * r[i];
        }
        cout << ans << '\n';
    }

    return 0;
}