#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int n, k;
LL ans, tmp;
LL num[maxn];

void dfs(int depth, LL sum, int k) {
    if (k == 0) {
        ans = max(ans, sum);
        return;
    }
    if (depth == n) {
        return;
    }
    if (k != 0) {
        dfs(depth + 1, sum ^ num[depth], k - 1);
    }
    if (k <= n - depth) {
        dfs(depth + 1, sum, k);
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    if (k > n / 2) {
        k = n - k;
        for (int i = 0; i < n; ++i) {
            tmp ^= num[i];
        }
    }
    dfs(0, tmp, k);
    cout << ans << endl;

    return 0;
}
