#include <bits/stdc++.h>
using namespace std;

long long getSum(vector<long long>& sum, int l, int r) {
    return sum[r] - sum[l - 1];
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<long long> a(n + 2), sum(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    const long long INF = 0x3f3f3f3f3f3f3f3f;
    vector<vector<long long>> lSumMax(4, vector<long long>(n + 2, -INF));
    for (int i = 1; i <= n; ++i) {
        lSumMax[0][i] =
            max(lSumMax[0][i - 1], getSum(sum, 1, i) + getSum(sum, i + 1, n));
        lSumMax[1][i] =
            max(lSumMax[1][i - 1], getSum(sum, 1, i) - getSum(sum, i + 1, n));
        lSumMax[2][i] =
            max(lSumMax[2][i - 1], -getSum(sum, 1, i) + getSum(sum, i + 1, n));
        lSumMax[3][i] =
            max(lSumMax[3][i - 1], -getSum(sum, 1, i) - getSum(sum, i + 1, n));
    }

    vector<vector<long long>> rSumMax(4, vector<long long>(n + 2, -INF));
    for (int i = n; i >= 1; --i) {
        rSumMax[0][i] =
            max(rSumMax[0][i + 1], getSum(sum, 1, i) + getSum(sum, i + 1, n));
        rSumMax[1][i] =
            max(rSumMax[1][i + 1], getSum(sum, 1, i) - getSum(sum, i + 1, n));
        rSumMax[2][i] =
            max(rSumMax[2][i + 1], -getSum(sum, 1, i) + getSum(sum, i + 1, n));
        rSumMax[3][i] =
            max(rSumMax[3][i + 1], -getSum(sum, 1, i) - getSum(sum, i + 1, n));
    }

    long long ans = 0;
    for (int i = 2; i < n; ++i) {
        ans = max(ans, max({lSumMax[0][i - 1] - getSum(sum, i + 1, n),
                            lSumMax[1][i - 1] + getSum(sum, i + 1, n),
                            lSumMax[2][i - 1] - getSum(sum, i + 1, n),
                            lSumMax[3][i - 1] + getSum(sum, i + 1, n)}) +
                           max({rSumMax[0][i + 1] - getSum(sum, 1, i),
                                rSumMax[1][i + 1] - getSum(sum, 1, i),
                                rSumMax[2][i + 1] + getSum(sum, 1, i),
                                rSumMax[3][i + 1] + getSum(sum, 1, i)}));
    }
    cout << ans << '\n';

    return 0;
}
