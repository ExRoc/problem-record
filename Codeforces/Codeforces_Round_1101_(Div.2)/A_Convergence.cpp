#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            ++cnt[a];
        }
        int ans = INT_MAX;
        for (const auto& [key, value] : cnt) {
            int lessCnt = 0;
            int moreCnt = 0;
            for (const auto& [key1, value1] : cnt) {
                if (key1 < key) {
                    lessCnt += value1;
                } else if (key1 > key) {
                    moreCnt += value1;
                }
            }
            ans = min(ans, max(lessCnt, moreCnt));
        }
        cout << ans << '\n';
    }

    return 0;
}