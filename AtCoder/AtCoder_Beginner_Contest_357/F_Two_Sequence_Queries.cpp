#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
const LL MOD = 998244353;
int n, q;
int cmd, l, r, x;
LL a[maxn], b[maxn];
LL sumab[maxn << 2];
LL suma[maxn << 2], sumb[maxn << 2], lazya[maxn << 2], lazyb[maxn << 2];

inline int lson(int rt) {
    return rt << 1;
}

inline int rson(int rt) {
    return rt << 1 | 1;
}

void pushUp(int rt) {
    int l = lson(rt);
    int r = rson(rt);
    suma[rt] = (suma[l] + suma[r]) % MOD;
    sumb[rt] = (sumb[l] + sumb[r]) % MOD;
    sumab[rt] = (sumab[l] + sumab[r]) % MOD;
}

void pushDown(int rt, LL len) {
    if (lazya[rt] == 0 && lazyb[rt] == 0) {
        return;
    }

    int l = lson(rt);
    int r = rson(rt);
    lazya[l] = (lazya[rt] + lazya[l]) % MOD;
    lazyb[l] = (lazyb[rt] + lazyb[l]) % MOD;
    lazya[r] = (lazya[rt] + lazya[r]) % MOD;
    lazyb[r] = (lazyb[rt] + lazyb[r]) % MOD;

    int rlen = (len >> 1);
    int llen = len - rlen;

    sumab[l] = (((sumab[l] + lazyb[rt] * suma[l] % MOD) % MOD +
                 lazya[rt] * sumb[l] % MOD) %
                    MOD +
                llen * lazya[rt] % MOD * lazyb[rt] % MOD) %
               MOD;
    sumab[r] = (((sumab[r] + lazyb[rt] * suma[r] % MOD) % MOD +
                 lazya[rt] * sumb[r] % MOD) %
                    MOD +
                rlen * lazya[rt] % MOD * lazyb[rt] % MOD) %
               MOD;

    suma[l] = (suma[l] + lazya[rt] * llen % MOD) % MOD;
    sumb[l] = (sumb[l] + lazyb[rt] * llen % MOD) % MOD;
    suma[r] = (suma[r] + lazya[rt] * rlen % MOD) % MOD;
    sumb[r] = (sumb[r] + lazyb[rt] * rlen % MOD) % MOD;

    lazya[rt] = 0;
    lazyb[rt] = 0;
}

void build(int rt, int l, int r) {
    lazya[rt] = lazyb[rt] = 0;
    if (l == r) {
        suma[rt] = a[l];
        sumb[rt] = b[l];
        sumab[rt] = (a[l] * b[l]) % MOD;
        return;
    }
    int m = (l + r) >> 1;
    build(lson(rt), l, m);
    build(rson(rt), m + 1, r);
    pushUp(rt);
}

void add(int rt, int l, int r, int L, int R, LL x, char cmd) {
    if (L <= l && r <= R) {
        if (cmd == 'a') {
            lazya[rt] = (lazya[rt] + x) % MOD;
            suma[rt] = (suma[rt] + x * (r - l + 1) % MOD) % MOD;
            sumab[rt] = (sumab[rt] + x * sumb[rt] % MOD) % MOD;
        } else {
            lazyb[rt] = (lazyb[rt] + x) % MOD;
            sumb[rt] = (sumb[rt] + x * (r - l + 1) % MOD) % MOD;
            sumab[rt] = (sumab[rt] + x * suma[rt] % MOD) % MOD;
        }
        return;
    }
    pushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) {
        add(lson(rt), l, m, L, R, x, cmd);
    }
    if (m < R) {
        add(rson(rt), m + 1, r, L, R, x, cmd);
    }
    pushUp(rt);
}

LL query(int rt, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
        return sumab[rt];
    }
    pushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    LL ret = 0;
    if (L <= m) {
        ret += query(lson(rt), l, m, L, R) % MOD;
    }
    if (R > m) {
        ret = (ret + query(rson(rt), m + 1, r, L, R)) % MOD;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    build(1, 1, n);
    while (q--) {
        cin >> cmd >> l >> r;
        if (cmd != 3) {
            cin >> x;
        }
        if (cmd == 1) {
            add(1, 1, n, l, r, x, 'a');
        }
        if (cmd == 2) {
            add(1, 1, n, l, r, x, 'b');
        }
        if (cmd == 3) {
            cout << query(1, 1, n, l, r) << endl;
        }
    }

    return 0;
}
