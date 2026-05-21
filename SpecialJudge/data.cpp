#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

string numToStr(int x) {
    string str;
    while (x != 0) {
        str = char('0' + x % 10) + str;
        x /= 10;
    }
    return str;
}

string getFileInName(int index) { return "data/" + numToStr(index) + ".in"; }

string getFileOutName(int index) { return "data/" + numToStr(index) + ".out"; }

LL getRand(LL l, LL r) {
    LL rnd = rand();
    rnd = (rnd << 15) | rand();
    rnd = (rnd << 15) | rand();
    rnd = (rnd << 15) | rand();
    return rnd % (r - l + 1) + l;
}

int main() {
    ios::sync_with_stdio(false);
    srand(time(0));

    int T = getRand(1, 1);
    cout << T << '\n';
    while (T--) {
        int n = getRand(1, 5);
        cout << n << '\n';
        for (int i = 0; i < n; ++i) {
            cout << getRand(-10, 10) << " ";
        }
        cout << '\n';
        for (int i = 0; i < n; ++i) {
            cout << getRand(0, 1);
        }
        cout << '\n';
        for (int i = 2; i <= n; ++i) {
            cout << i << " " << getRand(1, i - 1) << '\n';
        }
    }

    return 0;
}
