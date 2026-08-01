#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<__int128_t> x(N + 1, 0);
    for (int i = 2; i <= N; ++i) {
        long long d;
        cin >> d;
        x[i] = x[i - 1] + d;
    }
    vector<int> t(N + 1);
    int lastZeroIdx = 0;
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> t[i];
        if (t[i] == 1) {
            continue;
        }
        __int128_t dis = x[i] - x[lastZeroIdx];
        for (int j = lastZeroIdx + 1; j < i; ++j) {
            if (dis * (j - lastZeroIdx) !=
                (x[j] - x[lastZeroIdx]) * (i - lastZeroIdx)) {
                ++ans;
            }
        }
        lastZeroIdx = i;
    }
    cout << ans << '\n';

    return 0;
}