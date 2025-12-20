#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;

struct SegmentTree {
    int mx[maxn << 2], mn[maxn << 2];

    int lson(int rt) { return rt << 1; }

    int rson(int rt) { return rt << 1 | 1; }

    void pushUp(int rt) {
        int l = lson(rt);
        int r = rson(rt);
        mx[rt] = max(mx[l], mx[r]);
        mn[rt] = min(mn[l], mn[r]);
    }

    void build(int rt, int l, int r, int* num) {
        if (l == r) {
            mn[rt] = mx[rt] = num[l];
            return;
        }
        int m = (l + r) >> 1;
        build(lson(rt), l, m, num);
        build(rson(rt), m + 1, r, num);
        pushUp(rt);
    }

    void update(int rt, int l, int r, int idx, int x) {
        if (l == r) {
            mx[rt] = mn[rt] = x;
            return;
        }
        int m = (l + r) >> 1;
        if (idx <= m) {
            update(lson(rt), l, m, idx, x);
        } else {
            update(rson(rt), m + 1, r, idx, x);
        }
        pushUp(rt);
    }

    int queryMax(int rt, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return mx[rt];
        }
        int m = (l + r) >> 1;
        int ret = INT_MIN;
        if (L <= m) {
            ret = max(ret, queryMax(lson(rt), l, m, L, R));
        }
        if (m < R) {
            ret = max(ret, queryMax(rson(rt), m + 1, r, L, R));
        }
        return ret;
    }

    int queryMin(int rt, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return mn[rt];
        }
        int m = (l + r) >> 1;
        int ret = INT_MAX;
        if (L <= m) {
            ret = min(ret, queryMin(lson(rt), l, m, L, R));
        }
        if (m < R) {
            ret = min(ret, queryMin(rson(rt), m + 1, r, L, R));
        }
        return ret;
    }
};

int n, q, x, y, cmd, idx, l, r;
int xyAdd[maxn], xySub[maxn];
SegmentTree add, sub;

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        xyAdd[i] = x + y;
        xySub[i] = x - y;
    }
    add.build(1, 1, n, xyAdd);
    sub.build(1, 1, n, xySub);
    while (q--) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> idx >> x >> y;
            add.update(1, 1, n, idx, x + y);
            sub.update(1, 1, n, idx, x - y);
            continue;
        }
        cin >> l >> r >> x >> y;
        LL addMax = add.queryMax(1, 1, n, l, r);
        LL subMax = sub.queryMax(1, 1, n, l, r);
        LL addMin = add.queryMin(1, 1, n, l, r);
        LL subMin = sub.queryMin(1, 1, n, l, r);
        cout << max({x + y - addMin, x - y - subMin, y - x + subMax,
                     -x - y + addMax})
             << endl;
    }

    return 0;
}
