#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
const LL INF = 1000000000000000LL;
int T, n, m, posCnt, negCnt;
LL num[maxn];

LL solve1() {
    sort(num + 1, num + 1 + n);
    LL ans = 0;
    if (num[n - 1] <= 0) {
        ans = abs(num[n - 1]) / num[n] + 1;
        num[n - 1] += num[n] * ans;
    }
    LL mx = num[n];
    LL sec = num[n - 1];
    LL tmp = -1;
    LL ccnt = 0;
    while (mx <= INF) {
        LL ttmp = 0;
        for (int i = 0; i < m; ++i) {
            int idx = n - i;
            if (num[idx] > 0) {
                continue;
            }
            ttmp += abs(num[idx]) / mx + 1;
        }
        if (tmp == -1) {
            tmp = ttmp;
        } else {
            tmp = min(tmp, ttmp + ccnt);
        }
        sec += mx;
        ++ccnt;
        swap(sec, mx);
    }
    return ans + tmp;
}

LL solve2() {
    sort(num + 1, num + 1 + n);
    LL ans = 0;
    if (num[2] > 0) {
        ans = (num[2] - num[1] - 1) / abs(num[1]);
        num[2] += ans * num[1];
    }
    LL mn = num[1];
    LL sec = num[2];
    LL tmp = -1;
    LL ccnt = 0;
    while (mn >= -INF) {
        LL ttmp = 0;
        for (int i = 1; i <= n - m; ++i) {
            if (num[i] <= 0) {
                continue;
            }
            ttmp += (num[i] - mn - 1) / abs(mn);
        }
        if (tmp == -1) {
            tmp = ttmp;
        } else {
            tmp = min(tmp, ttmp + ccnt);
        }
        sec += mn;
        ++ccnt;
        swap(sec, mn);
    }
    return ans + tmp;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n >> m;
        posCnt = 0;
        negCnt = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
            if (num[i] > 0) {
                ++posCnt;
            }
            if (num[i] < 0) {
                ++negCnt;
            }
        }
        if (m > n) {
            cout << -1 << endl;
            continue;
        }
        if (posCnt == m) {
            cout << 0 << endl;
            continue;
        }
        if (posCnt == 0) {
            cout << -1 << endl;
            continue;
        }
        if (posCnt < m) {
            cout << solve1() << endl;
            continue;
        }
        if (negCnt == 0) {
            cout << -1 << endl;
            continue;
        }
        cout << solve2() << endl;
    }

    return 0;
}
