#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
double R;
LL ans;

LL cal(double x) {
    double r = (LL)(sqrt(R * R - x * x) - 0.5) + 0.5;
    double l = -r;
    return r - l;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> R;
    ans += cal(0.5);
    for (double i = 1.5; i <= R; i += 1) {
        ans += 2 * cal(i);
    }
    cout << ans << endl;

    return 0;
}
