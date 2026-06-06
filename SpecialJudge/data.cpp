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

    cout << 1 << '\n';
    int N = getRand(1, 5);
    int S = getRand(1, 100);
    cout << N << " " << S << '\n';
    for (int i = 0; i < N; ++i) {
        cout << getRand(0, 100) << " ";
    }

    return 0;
}
