#include <bits/stdc++.h>
using namespace std;

void dfs(int depth, int n, vector<int>& num, vector<int>& p, int& ans) {
    if (depth == n) {
        vector<int> cnt(2, 0);
        for (int i = 0; i < n; ++i) {
            ++cnt[num[i]];
            if (cnt[num[i] ^ 1] != p[i]) {
                return;
            }
        }
        ++ans;
        // for (int i = 0; i < n; ++i) {
        //     cout << num[i] << ' ';
        // }
        // cout << '\n';
        return;
    }
    num[depth] = 0;
    dfs(depth + 1, n, num, p, ans);
    num[depth] = 1;
    dfs(depth + 1, n, num, p, ans);
}

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    int ans = 0;
    vector<int> num(n);
    dfs(0, n, num, p, ans);
    cout << ans << '\n';

    return 0;
}