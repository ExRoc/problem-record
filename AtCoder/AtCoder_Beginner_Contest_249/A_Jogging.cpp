#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
int a, b, c, d, e, f, g;

int cal(int a, int b, int c, int d) {
    int now = 0;
    int pre = 0;
    int ret = 0;
    while (now < d) {
        pre = now;
        now = min(now + a, d);
        ret += (now - pre) * b;
        now += c;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> a >> b >> c >> d >> e >> f >> g;
    int Takahashi = cal(a, b, c, g);
    int Aoki = cal(d, e, f, g);
    if (Takahashi > Aoki) {
        cout << "Takahashi" << endl;
    } else if (Takahashi < Aoki) {
        cout << "Aoki" << endl;
    } else {
        cout << "Draw" << endl;
    }

    return 0;
}
