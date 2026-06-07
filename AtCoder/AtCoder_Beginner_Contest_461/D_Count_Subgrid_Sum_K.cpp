#include <bits/stdc++.h>
using namespace std;

int getSum(const vector<vector<int>>& sum, int x1, int y1, int x2, int y2) {
    if (x2 < x1) {
        return 0;
    }
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] +
           sum[x1 - 1][y1 - 1];
}

int main() {
    ios::sync_with_stdio(false);

    int H, W, K;
    cin >> H >> W >> K;
    vector<vector<int>> sum(H + 1, vector<int>(W + 1, 0));
    for (int i = 0; i < H; ++i) {
        string S;
        cin >> S;
        for (int j = 0; j < W; ++j) {
            sum[i + 1][j + 1] =
                sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + S[j] - '0';
        }
    }
    long long ans = 0;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            int idx1 = H;
            int idx2 = H;
            for (int k = j; k <= W; ++k) {
                while (idx1 >= i && getSum(sum, i, j, idx1, k) > K) {
                    --idx1;
                }
                while (idx2 >= i && getSum(sum, i, j, idx2, k) > K - 1) {
                    --idx2;
                }
                if (getSum(sum, i, j, idx1, k) == K) {
                    ans += idx1 - idx2;
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}