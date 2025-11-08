#include <iostream>
#include <map>
#define int long long
using namespace std;
int n, k, sum, cnt, res, f[3];
map<int, int> t;
void sol() {
    cin >> n >> k, k--, sum = res = cnt = f[1] = f[2] = 0, t.clear();
    for (int i = 1, x, y; i <= n; i++)
        cin >> x >> y, t[x] += y;
    for (auto te : t) {
        int x = te.second;
        sum += x / 3;
        if (x <= 2)
            res += x;
        else
            res += 2, cnt += ((x - 2) / 3), f[(x - 2) % 3]++;
    }
    if (sum < k) {
        cout << -1 << '\n';
        return;
    }
    cnt = min(cnt, k), res += cnt * 3, k -= cnt;
    for (int i = 2; i >= 1; i--) {
        int tx = min(f[i], k);
        k -= tx, res += tx * i;
    }
    cout << res + 1 << '\n';
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int TT;
    cin >> TT;
    while (TT--)
        sol();
    return 0;
}