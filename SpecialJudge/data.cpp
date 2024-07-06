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

string getFileInName(int index) {
    return "data/" + numToStr(index) + ".in";
}

string getFileOutName(int index) {
    return "data/" + numToStr(index) + ".out";
}

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

    cout << 1 << endl;
    int n = getRand(1, 12);
    n = 12;
    int m = getRand(1, 20);
    m = 20;
    int k = getRand(1, 20);
    k = 20;
    cout << n << " " << m << " " << k << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (getRand(0, 1) == 0) {
                cout << ".";
            } else {
                cout << "Q";
            }
        }
        cout << endl;
    }

    return 0;
}
