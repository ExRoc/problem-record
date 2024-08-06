#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
LL sx, sy, tx, ty, ans;

bool canGoRight(LL x, LL y) {
    return (x + y) % 2 == 0;
}

bool canGoLeft(LL x, LL y) {
    return (x + y) % 2 != 0;
}

void goLeft(LL& x, LL& y) {
    --x;
}

void goRight(LL& x, LL& y) {
    ++x;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> sx >> sy >> tx >> ty;
    if (sx >= tx) {
        swap(sx, tx);
        swap(sy, ty);
    }
    if (tx > sx && canGoRight(sx, sy)) {
        goRight(sx, sy);
    }
    if (tx > sx && canGoLeft(tx, ty)) {
        goLeft(tx, ty);
    }
    ans += abs(ty - sy);
    sx = min(abs(ty - sy) + sx, tx);
    ans += (abs(tx - sx) + 1) / 2;
    cout << ans << endl;

    return 0;
}
