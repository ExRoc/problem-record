#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        long long X;
        cin >> N >> X;
        vector<long long> A;
        A.push_back(X + 1);
        for (int i = 0; i < N; ++i) {
            long long tmp;
            cin >> tmp;
            if (tmp < A.back()) {
                A.push_back(tmp);
            }
        }

        N = A.size();
        if (N == 1) {
            cout << 0 << '\n';
            continue;
        }
        vector<map<long long, long long>> mp(N);
        mp[1][X] = 1;
        long long ans = 0;
        for (int i = 1; i < N; ++i) {
            for (const auto& [key, value] : mp[i]) {
                ans += key / A[i] * value;
                if (i + 1 < N) {
                    mp[i + 1][A[i] - 1] += key / A[i] * value;
                }
                if (key % A[i] != 0) {
                    int idx = lower_bound(A.begin(), A.end(), key % A[i],
                                          [&](long long a, long long b) {
                                              return a > b;
                                          }) -
                              A.begin();
                    if (idx != N) {
                        mp[idx][key % A[i]] += value;
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}