#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int maxn = 1000001;
    vector<long double> sum(maxn);
    for (int i = 1; i < maxn; ++i) {
        sum[i] = sum[i - 1] + (long double)1.0 / i;
    }

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        if (N == 1) {
            printf("-1.000000\n");
            continue;
        }
        long double ans = -1e18;
        for (int i = 2; i <= N; ++i) {
            ans = max(ans, 1 - i + i * (sum[N] - sum[i - 1]));
        }
        printf("%.6lf\n", (double)(ans / N));
    }

    return 0;
}