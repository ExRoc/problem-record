#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<map<int, int>> steps(n);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            int step = 0;
            steps[i][x] = 0;
            while (x != 1) {
                if (x % 2 == 0) {
                    x >>= 1;
                } else {
                    ++x;
                }
                ++step;
                if (steps[i].find(x) == steps[i].end()) {
                    steps[i][x] = step;
                }
            }
            if (steps[i].find(2) == steps[i].end()) {
                ++step;
                steps[i][2] = step;
            }
        }
        set<int> st;
        for (auto [num, step] : steps[0]) {
            st.insert(num);
        }
        for (int i = 1; i < n; ++i) {
            vector<int> eraseNums;
            for (int num : st) {
                if (steps[i].find(num) == steps[i].end()) {
                    eraseNums.push_back(num);
                }
            }
            for (int num : eraseNums) {
                st.erase(num);
            }
        }
        map<int, long long> cntMap;
        for (int i = 0; i < n; ++i) {
            for (int num : st) {
                cntMap[num] += steps[i][num];
            }
        }
        long long ans = LONG_LONG_MAX;
        for (auto [num, cnt] : cntMap) {
            ans = min(ans, cnt);
        }
        cout << ans << '\n';
    }

    return 0;
}