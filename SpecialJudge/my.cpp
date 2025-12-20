#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_HOUSE 10001
#define MAX_STEAL 10001

int nums[MAX_HOUSE];
int dp[MAX_HOUSE][MAX_STEAL];

int maxLinearValue(int start, int len, int max_k) {
    if (len == 0)
        return 0;

    for (int i = 0; i <= len; ++i) {
        dp[i][0] = 0;
    }
    for (int k = 0; k <= max_k; ++k) {
        dp[0][k] = 0;
    }

    dp[1][1] = nums[start];

    for (int k = 2; k <= max_k; ++k) {
        dp[1][k] = 0;
    }

    for (int i = 2; i <= len; ++i) {
        int current_house = start + i - 1;
        for (int k = 1; k <= min(i, max_k); ++k) {
            dp[i][k] = dp[i - 1][k];

            if (i >= 2) {
                dp[i][k] =
                    max(dp[i][k], dp[i - 2][k - 1] + nums[current_house]);
            } else {
                dp[i][k] = max(dp[i][k], nums[current_house]);
            }
        }

        for (int k = i + 1; k <= max_k; ++k) {
            dp[i][k] = 0;
        }
    }

    int res = 0;
    for (int k = 0; k <= max_k; ++k) {
        res = max(res, dp[len][k]);
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }

    if (n == 1) {
        cout << (m >= 1 ? nums[1] : 0) << endl;
        return 0;
    }

    int res1 = maxLinearValue(2, n - 1, m);

    int res2 = maxLinearValue(1, n - 1, m);

    cout << max(res1, res2) << endl;
    return 0;
}