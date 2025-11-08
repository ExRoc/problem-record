#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 500000 + 100;
int n;
LL ans, x, mn, mx;
map<LL, LL> mp;
map<LL, LL>::iterator it1, it2;

void solve(LL x) {
    if (x < mn) {
        if (mp.size() == 1) {
            LL tmp = mn - x;
            mp[0] = tmp;
            mp[x] = tmp;
            ans += tmp * 2;
        } else {
            ans -= mp[mn];
            mp[x] = mn - x;
            it1 = it2 = mp.begin();
            ++it2;
            mp[mn] = min(it2->first - it1->first, mn - x);
            ans += mp[x] + mp[mn];
        }
    } else if (x > mx) {
        if (mp.size() == 1) {
            ans += 2 * (x - mx);
            mp[0] = mp[x] = x - mx;
        } else {
            it1 = it2 = mp.end();
            --it2;
            --it1;
            --it1;
            ans -= mp[mx];
            mp[x] = x - mx;
            mp[mx] = min(mx - it1->first, x - mx);
            ans += mp[x] + mp[mx];
        }
    } else {
        it1 = it2 = mp.lower_bound(x);
        --it1;
        LL tmp = it2->first - it1->first;
        ans -= it1->second + it2->second;
        mp[x] = min(x - it1->first, it2->first - x);
        it1->second = min(it1->second, x - it1->first);
        it2->second = min(it2->second, it2->first - x);
        ans += it1->second + it2->second + mp[x];
    }
    cout << ans << endl;
    mn = min(mn, x);
    mx = max(mx, x);
}

int main() {
    ios::sync_with_stdio(false);

    // 题意：输入 N 与 N 个数字 X_i，最开始有一个人站在位置 0
    // 后面第 i 个人站到位置 X_i
    // 每加入一个人，都输出一个整数 D_i
    // 定义 d_j 为与第 j 个人最近的另一个人的距离
    // D_i 为前 i 个人的 d_j (0 <= j <= i) 的和
    // N 为 5e5，每个 X_i 都不相同
    mp[0] = INT_MAX;
    mn = mx = 0;
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        solve(x);
    }

    return 0;
}
