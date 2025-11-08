#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 300000 + 100;
int T, n;
char str[maxn];
vector<int> G[maxn], Gr[maxn];
int dp[maxn], dpr[maxn], degin[maxn], deginr[maxn], sum[maxn];
queue<int> que;

void topsort(vector<int> G[maxn], int degin[maxn], int dp[maxn]) {
    for (int i = 1; i <= n; ++i) {
        if (degin[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int tmp = que.front();
        que.pop();
        for (int pos : G[tmp]) {
            --degin[pos];
            dp[pos] += dp[tmp];
            if (degin[pos] == 0) {
                que.push(pos);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    // 题意：输入 T，后面有 T 组数据，对于每组数据：
    // 输入 N 和长度为 N-1 的字符串，字符串只包含 'L' 与 'R' 两种字符
    // 如果第 i 个字符（i 从 1 开始）为 L，那么数字 i + 1 只能写在数字 i 的左边
    // 如果第 i 个字符（i 从 1 开始）为 R，那么数字 i + 1 只能写在数字 i 的右边
    // 要求把从 1 到 N N 个数字填入 1 到 N N 个位置，每个数字必须出现 1 次
    // 要求数字之间位置的相对关系满足字符串中 LR 的要求
    // 这样右多种可能的排列，求出所有排列中，第 i 个位置可能出现的不同的数字个数
    // 从 1 到 N 输出答案，N 为 3e5
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s", &n, str + 1);
        for (int i = 1; i <= n; ++i) {
            G[i].clear();
            Gr[i].clear();
            degin[i] = deginr[i] = 0;
            dp[i] = dpr[i] = 1;
            sum[i] = 0;
        }
        for (int i = 1; i < n; ++i) {
            if (str[i] == 'L') {
                G[i + 1].push_back(i);
                Gr[i].push_back(i + 1);
                ++degin[i];
                ++deginr[i + 1];
            } else {
                G[i].push_back(i + 1);
                Gr[i + 1].push_back(i);
                ++degin[i + 1];
                ++deginr[i];
            }
        }
        topsort(G, degin, dp);
        topsort(Gr, deginr, dpr);
        for (int i = 1; i <= n; ++i) {
            ++sum[dp[i]];
            --sum[(n - dpr[i] + 1) + 1];
            // cout << i << ": [" << dp[i] << ", " << dpr[i] << "]" << endl;
        }
        for (int i = 1; i <= n; ++i) {
            sum[i] += sum[i - 1];
            cout << sum[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
