#include <bits/stdc++.h>
using namespace std;

long long C(int n, int m, const vector<long long>& fac) {
    return fac[n] / fac[m] / fac[n - m];
}

long long cal(int n, int m, const vector<int>& cnt,
              const vector<long long>& fac) {
    int left = n;
    int lastCnt = 0;
    long long ans = 1;
    int a = 0;
    for (int i = 0; i < m; ++i) {
        ans *= C(left, cnt[i], fac);
        left -= cnt[i];
        if (cnt[i] == lastCnt) {
            ++a;
        } else {
            ans /= fac[a];
            a = 1;
        }
        lastCnt = cnt[i];
    }
    return ans / fac[a];
}

long long dfs(int depth, int left, int n, int m, vector<int>& cnt,
              const vector<long long>& fac) {
    if (left == 0) {
        if (depth == m) {
            return cal(n, m, cnt, fac);
        }
        return 0;
    }
    if (depth == 0) {
        long long ans = 0;
        for (int i = 1; i <= left; ++i) {
            cnt[depth] = i;
            ans += dfs(depth + 1, left - i, n, m, cnt, fac);
        }
        return ans;
    }
    if (left < cnt[depth - 1]) {
        return 0;
    }
    long long ans = 0;
    for (int i = cnt[depth - 1]; i <= left; ++i) {
        cnt[depth] = i;
        ans += dfs(depth + 1, left - i, n, m, cnt, fac);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<long long> fac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = fac[i - 1] * i;
    }
    vector<int> cnt(m);
    cout << dfs(0, n, n, m, cnt, fac) << '\n';

    return 0;
}