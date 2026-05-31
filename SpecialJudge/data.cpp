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

    const int maxn = 300000;
    int N = getRand(1, maxn);
    int Q = getRand(1, maxn);
    cout << N << " " << Q << '\n';
    while (Q--) {
        int cmd = getRand(1, 2);
        int x;
        if (cmd == 1) {
            x = getRand(1, N);
        } else {
            x = getRand(1, maxn);
        }
        cout << cmd << " " << x << '\n';
    }

    return 0;
}
