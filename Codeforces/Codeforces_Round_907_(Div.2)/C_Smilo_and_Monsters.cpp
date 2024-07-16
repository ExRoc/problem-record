#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int T, n, l, r, cnt;
LL ans;
int num[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
        }
        sort(num + 1, num + 1 + n);
        l = 1;
        r = n;
        cnt = 0;
        ans = 0;
        while (l < r) {
            if (cnt + num[l] <= num[r]) {
                ans += num[l];
                cnt += num[l];
                num[l] = 0;
                ++l;
                continue;
            }
            ans += num[r] - cnt;
            num[l] = num[l] + cnt - num[r];
            num[r] = 0;
            cnt = 0;
            --r;
            ++ans;
        }
        if (num[l] == 0) {
            cout << ans << endl;
            continue;
        }
        if (num[l] == 1) {
            ++ans;
        } else {
            if (cnt >= num[l]) {
                ++ans;
            } else {
                ans += (num[l] + cnt) / 2 - cnt + 1 + ((num[l] + cnt) % 2);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
