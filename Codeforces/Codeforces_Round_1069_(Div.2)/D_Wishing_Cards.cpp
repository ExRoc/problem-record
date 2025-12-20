#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 360 + 100;
int T, n, K, cnt, num;
set<int> st;
int dp[maxn][maxn], dptmp[maxn][maxn], dpmax[maxn][maxn];

void init() {
    st.clear();
    cnt = 0;
    for (int i = 0; i <= K; ++i) {
        memset(dp[i], -1, sizeof(int) * (K + 1));
    }
    dp[0][0] = 0;
    for (int k = 0; k <= K; ++k) {
        dpmax[0][k] = dp[0][k];
        for (int j = 1; j <= K; ++j) {
            dpmax[j][k] = max(dpmax[j - 1][k], dp[j][k]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n >> K;
        init();
        for (int i = 1; i <= n; ++i) {
            cin >> num;
            ++cnt;
            if (st.find(num) != st.end()) {
                continue;
            }
            st.insert(num);
            for (int j = 0; j <= K; ++j) {
                for (int k = 0; k <= K; ++k) {
                    if (dp[j][k] != -1) {
                        dp[j][k] = dp[j][k] + j * (cnt - 1);
                        dptmp[j][k] = dp[j][k] + j;
                    } else {
                        dp[j][k] = -1;
                        dptmp[j][k] = -1;
                    }
                }
            }
            for (int k = 0; k <= K; ++k) {
                dpmax[0][k] = dp[0][k];
                for (int j = 1; j <= K; ++j) {
                    dpmax[j][k] = max(dpmax[j - 1][k], dp[j][k]);
                }
            }
            for (int j = 1; j <= num; ++j) {
                for (int k = 0; k <= K; ++k) {
                    if (k >= j) {
                        if (dpmax[j][k - j] != -1) {
                            dptmp[j][k] = max(dptmp[j][k], dpmax[j][k - j] + j);
                        }
                    }
                }
            }
            for (int j = 0; j <= K; ++j) {
                memcpy(dp[j], dptmp[j], sizeof(int) * (K + 1));
            }
            cnt = 0;
        }
        int ans = 0;
        for (int j = 0; j <= K; ++j) {
            for (int k = 0; k <= K; ++k) {
                if (dp[j][k] != -1) {
                    dp[j][k] += j * cnt;
                    ans = max(ans, dp[j][k]);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}