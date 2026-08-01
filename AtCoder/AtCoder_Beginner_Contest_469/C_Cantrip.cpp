#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string S;
    cin >> S;
    S = ' ' + S;
    vector<int> sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        sum[i] = sum[i - 1];
        if (S[i] == 'x') {
            ++sum[i];
        }
    }
    int oCnt = 0;
    for (int i = 1; i <= N; ++i) {
        if (S[i] == 'o') {
            ++oCnt;
        }
        if (oCnt == 0) {
            cout << i << '\n';
            continue;
        }
        int high = N + 1;
        int low = i;
        while (high - low > 1) {
            int mid = (high + low) >> 1;
            if (oCnt - (sum[mid] - sum[i]) <= 0) {
                high = mid;
            } else {
                low = mid;
            }
        }
        cout << min(high, N) << '\n';
    }

    return 0;
}