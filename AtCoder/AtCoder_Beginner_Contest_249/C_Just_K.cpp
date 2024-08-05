#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
int n, k, ans;
string str;
int cnt[15][26], ccnt[26];

void dfs(int depth) {
    if (depth == n) {
        int tmp = 0;
        for (int i = 0; i < 26; ++i) {
            if (ccnt[i] == k) {
                ++tmp;
            }
        }
        ans = max(ans, tmp);
        return;
    }
    dfs(depth + 1);
    for (int i = 0; i < 26; ++i) {
        ccnt[i] += cnt[depth][i];
    }
    dfs(depth + 1);
    for (int i = 0; i < 26; ++i) {
        ccnt[i] -= cnt[depth][i];
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        for (char ch : str) {
            cnt[i][ch - 'a'] = 1;
        }
    }
    dfs(0);
    cout << ans << endl;

    return 0;
}
