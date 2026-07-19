#include <bits/stdc++.h>
using namespace std;

long long getSum(const vector<long long>& sum, int minX, int maxX, int n) {
    minX = max(minX, 1);
    maxX = min(n, maxX);
    return sum[maxX] - sum[minX - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    long long H;
    cin >> n >> m >> s >> H;
    long long sum = 0;
    vector<vector<long long>> h(n + 1, vector<long long>(m + 1, 0));
    for (int i = 0; i < s; ++i) {
        int x, y;
        cin >> x >> y;
        cin >> h[x][y];
        sum += h[x][y];
    }
    if (sum < H) {
        cout << "Happy end" << '\n';
        return 0;
    }
    if (sum == H) {
        cout << "Normal end" << '\n';
        return 0;
    }
    int wx, wy;
    cin >> wx >> wy;
    vector<vector<long long>> k1Sum(
        m + n - 1, vector<long long>(n + 1, 0));  // 第一维 = b + n - 1
    for (int b = 1 - n; b <= m - 1; ++b) {
        for (int x = 1; x <= n; ++x) {
            if (x + b <= m && x + b >= 1) {
                k1Sum[b + n - 1][x] = k1Sum[b + n - 1][x - 1] + h[x][x + b];
            }
        }
    }
    vector<vector<long long>> k_1Sum(
        n + m - 1, vector<long long>(n + 1, 0));  // 第一维 = b - 2
    for (int b = 2; b <= n + m; ++b) {
        for (int x = 1; x <= n; ++x) {
            if (b - x >= 1 && b - x <= n) {
                k_1Sum[b - 2][x] = k_1Sum[b - 2][x - 1] + h[b - x][x];
            }
        }
    }
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= m; ++y) {
            if (x == wx && y == wy) {
                continue;
            }
            long long sumTmp = h[x][y];
            if (sum - sumTmp < H) {
                cout << "Normal end" << '\n';
                return 0;
            }
            int dTop = abs(wx - x) + abs(wy - y);
            for (int d = 1; d < dTop; ++d) {
                int idx = y - (x - d) + n - 1;
                if (idx >= 0 && idx < m + n - 1) {
                    sumTmp += getSum(k1Sum[idx], x - d, x - 1, n);
                }
                idx = y - d + 1 - (x + 1) + n - 1;
                if (idx >= 0 && idx < m + n - 1) {
                    sumTmp += getSum(k1Sum[idx], x + 1, x + d, n);
                }
                idx = y - 1 + (x - d + 1) - 2;
                if (idx >= 0 && idx < n + m - 1) {
                    sumTmp += getSum(k_1Sum[idx], x - d + 1, x, n);
                }
                idx = y + d + x - 2;
                if (idx >= 0 && idx < n + m - 1) {
                    sumTmp += getSum(k_1Sum[idx], x, x + d - 1, n);
                }
                if (sum - sumTmp < H && H - (sum - sumTmp) >= d) {
                    cout << "Normal end" << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "Bad end" << '\n';

    return 0;
}