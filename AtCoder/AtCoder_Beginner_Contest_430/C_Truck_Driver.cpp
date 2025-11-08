#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 300000 + 100;
int n, a, b;
LL ans;
char str[maxn];
int suma[maxn], sumb[maxn];

LL cal(int idx) {
    return max(0LL,
               (LL)(lower_bound(sumb, sumb + n + 1, sumb[idx] + b) - sumb) -
                   (lower_bound(suma, suma + n + 1, suma[idx] + a) - suma));
}

int main() {
    ios::sync_with_stdio(false);

    // 题意：输入 N A B + 一个长度为 N 的字符串，N 为 3e5
    // 找出有多少个区间，区间内字串 a 字符的个数 >= A 且 B 字符的个数 < B
    scanf("%d%d%d%s", &n, &a, &b, str + 1);
    for (int i = 1; i <= n; ++i) {
        suma[i] = suma[i - 1];
        sumb[i] = sumb[i - 1];
        if (str[i] == 'a') {
            ++suma[i];
        } else {
            ++sumb[i];
        }
    }
    for (int i = 0; i <= n; ++i) {
        ans += cal(i);
        // cout << "i = " << i << " cal = " << cal(i) << endl;
    }
    cout << ans << endl;

    return 0;
}
