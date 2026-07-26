#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        map<int, int> aCnt;
        for (int i = 0; i < N; ++i) {
            int a;
            cin >> a;
            ++aCnt[a];
        }
        vector<int> b(N);
        for (int i = 0; i < N; ++i) {
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            map<int, int>::iterator it = aCnt.lower_bound(K - b[i]);
            if (it == aCnt.end()) {
                continue;
            }
            ++ans;
            --it->second;
            if (it->second == 0) {
                aCnt.erase(it);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}