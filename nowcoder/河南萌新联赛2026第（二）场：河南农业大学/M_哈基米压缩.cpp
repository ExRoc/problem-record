#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, long long>> vl(n + 1, make_pair(0, 0));
    for (int i = 1; i <= n; ++i) {
        cin >> vl[i].first >> vl[i].second;
        vl[i].second += vl[i - 1].second;
    }
    int T;
    cin >> T;
    while (T--) {
        long long x;
        cin >> x;
        int low = 0;
        int high = n;
        while (high - low > 1) {
            int mid = (high + low) >> 1;
            if (vl[mid].second >= x) {
                high = mid;
            } else {
                low = mid;
            }
        }
        cout << vl[high].first << '\n';
    }

    return 0;
}