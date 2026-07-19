#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;
        int top = (1 << K) - 1;
        map<int, int> AIdx;
        for (int i = 0; i < N; ++i) {
            int A;
            cin >> A;
            AIdx[A] = i;
        }
        int ans = 0;
        vector<int> dp;
        for (int i = 0; i < M; ++i) {
            int B;
            cin >> B;
            int A = (top ^ B);
            if (AIdx.find(A) == AIdx.end()) {
                continue;
            }
            int idx = AIdx[A];
            int dpIdx = lower_bound(dp.begin(), dp.end(), idx) - dp.begin();
            if (dpIdx == dp.size()) {
                dp.push_back(idx);
            } else {
                dp[dpIdx] = idx;
            }
        }
        cout << dp.size() << '\n';
    }

    return 0;
}