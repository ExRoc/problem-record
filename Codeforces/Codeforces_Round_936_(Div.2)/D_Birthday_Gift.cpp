#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
int T, n, x, cnt, dig, ans;
bool flag, ed;
int num[maxn];
int fa[maxn];

int Find(int x) {
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

void unit(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x != y) {
        if (x > y) {
            swap(x, y);
        }
        --cnt;
        fa[x] = y;
        num[y] ^= num[x];
    }
}

void solveHigh(int d) {
    int l = 0;
    for (int i = 1; i <= n; ++i) {
        i = Find(i);
        if ((num[i] >> d) & 1) {
            if (l == 0) {
                l = i;
            } else {
                for (int j = l; j < i; ++j) {
                    unit(j, i);
                }
                l = 0;
            }
        }
    }
    if (l != 0) {
        flag = false;
        return;
    }
    if (d == 0) {
        ans = max(ans, cnt);
    }
}

void solveLow(int d) {
    if (((x >> d) & 1) == 0) {
        solveHigh(d);
        return;
    }

    int l = 0;
    int ansTmp = 0;
    bool canEd = true;
    for (int i = 1; i <= n; ++i) {
        i = Find(i);
        if ((num[i] >> d) & 1) {
            canEd = false;
            if (l == 0) {
                l = i;
            } else {
                ++ansTmp;
                l = 0;
            }
        } else {
            if (l == 0) {
                ++ansTmp;
            }
        }
    }
    if (l == 0) {
        ans = max(ans, ansTmp);
    }
    if (canEd) {
        ed = true;
    }
    if (d == 0) {
        ans = max(ans, cnt);
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n >> x;
        cnt = n;
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
            cin >> num[i];
        }
        dig = 0;
        for (int i = 0; i < 30; ++i) {
            if ((x & (1 << i)) != 0) {
                dig = i;
            }
        }
        ans = 0;
        flag = true;
        ed = false;
        for (int d = 29; d >= 0; --d) {
            if (d > dig) {
                solveHigh(d);
                if (!flag) {
                    break;
                }
                continue;
            }
            solveLow(d);
            if (!flag) {
                break;
            }
            if (ed) {
                break;
            }
        }
        if (ans == 0 && !flag) {
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;
    }

    return 0;
}
