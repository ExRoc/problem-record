#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    map<int, vector<int>> xYs, yXs;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        xYs[x].push_back(y);
        yXs[y].push_back(x);
    }
    long long ans = 0;
    map<int, vector<int>>::iterator it;
    for (it = xYs.begin(); it != xYs.end(); ++it) {
        vector<int>& ys = it->second;
        sort(ys.begin(), ys.end());
    }
    for (it = yXs.begin(); it != yXs.end(); ++it) {
        vector<int>& xs = it->second;
        sort(xs.begin(), xs.end());
    }
    for (it = xYs.begin(); it != xYs.end(); ++it) {
        int x = it->first;
        vector<int>& ys = it->second;
        for (int i = 0; i < (int)ys.size(); ++i) {
            for (int j = i + 1; j < (int)ys.size(); ++j) {
                if ((ys[j] - ys[i]) % 2 != 0) {
                    continue;
                }
                int mid = (ys[j] + ys[i]) / 2;
                if (yXs[mid].empty()) {
                    continue;
                }
                vector<int>& xs = yXs[mid];
                ans += xs.size() - (upper_bound(xs.begin(), xs.end(), x) -
                                    lower_bound(xs.begin(), xs.end(), x));
            }
        }
    }
    for (it = yXs.begin(); it != yXs.end(); ++it) {
        int y = it->first;
        vector<int>& xs = it->second;
        for (int i = 0; i < (int)xs.size(); ++i) {
            for (int j = i + 1; j < (int)xs.size(); ++j) {
                if ((xs[j] - xs[i]) % 2 != 0) {
                    continue;
                }
                int mid = (xs[i] + xs[j]) / 2;
                if (xYs[mid].empty()) {
                    continue;
                }
                vector<int>& ys = xYs[mid];
                ans += ys.size() - (upper_bound(ys.begin(), ys.end(), y) -
                                    lower_bound(ys.begin(), ys.end(), y));
            }
        }
    }
    cout << ans << '\n';

    return 0;
}