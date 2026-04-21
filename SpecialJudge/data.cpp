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

    int n = getRand(2, 10);
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        int x = getRand(0, 2);
        if (x == 0) {
            cout << 'Q';
        } else if (x == 1) {
            cout << 'L';
        } else {
            cout << '?';
        }
    }
    cout << endl;

    return 0;
}
