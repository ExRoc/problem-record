#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 81;
const LL MOD = 998244353;
int n;
int num[maxn];
LL dp[2][maxn][maxn * maxn][maxn];
vector<int> sand, sand2;
LL ans[maxn];
map<int, int> mp;
map<int, int>::iterator it;

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
        sand2.push_back(num[i]);
        for (int j = 1; j < i; ++j) {
            sand.push_back(num[i] - num[j]);
        }
    }
    sort(sand.begin(), sand.end());
    sand.erase(unique(sand.begin(), sand.end()), sand.end());
    sort(sand2.begin(), sand2.end());
    sand2.erase(unique(sand2.begin(), sand2.end()), sand2.end());
    for (int i = 0; i < (int)sand2.size(); ++i) {
        mp[sand2[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        int mpNum = mp[num[i]];
        int now = (i & 1);
        int pre = (now ^ 1);
        for (int j = 1; j <= i; ++j) {
            for (int k = 0; k < (int)sand.size(); ++k) {
                for (int l = 0; l < (int)sand2.size(); ++l) {
                    dp[now][j][k][l] = dp[pre][j][k][l];
                }
            }
        }
        for (int k = 0; k < (int)sand.size(); ++k) {
            dp[now][1][k][mpNum] = (dp[now][1][k][mpNum] + 1) % MOD;
        }
        for (int j = 2; j <= i; ++j) {
            for (int k = 0; k < (int)sand.size(); ++k) {
                int d = sand[k];
                it = mp.find(num[i] - d);
                if (it != mp.end()) {
                    dp[now][j][k][mpNum] =
                        (dp[now][j][k][mpNum] + dp[pre][j - 1][k][it->second]) %
                        MOD;
                }
            }
        }
    }
    for (int j = 1; j <= n; ++j) {
        for (int k = 0; k < (int)sand.size(); ++k) {
            for (int l = 0; l < (int)sand2.size(); ++l) {
                ans[j] = (ans[j] + dp[n & 1][j][k][l]) % MOD;
            }
        }
    }
    cout << n << " ";
    for (int i = 2; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
