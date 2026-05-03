#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> num(n + 1);
    vector<vector<int>> sum(4, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
        --num[i];
        for (int j = 0; j < 4; ++j) {
            sum[j][i] = sum[j][i - 1];
        }
        ++sum[num[i]][i];
    }
    int ans = n;
    for (int i = 1; i <= n; ++i) {
        if (sum[0][n] - sum[0][i - 1] == 0 || sum[1][n] - sum[1][i - 1] == 0 ||
            sum[2][n] - sum[2][i - 1] == 0 || sum[3][n] - sum[3][i - 1] < k) {
            break;
        }
        int low = i;
        int high = n;
        int mid;
        while (high - low > 1) {
            mid = (high + low) >> 1;
            if (sum[0][mid] - sum[0][i - 1] >= 1 &&
                sum[1][mid] - sum[1][i - 1] >= 1 &&
                sum[2][mid] - sum[2][i - 1] >= 1 &&
                sum[3][mid] - sum[3][i - 1] >= k) {
                high = mid;
            } else {
                low = mid;
            }
        }
        ans = min(ans, high - i + 1);
    }
    cout << ans << '\n';

    return 0;
}