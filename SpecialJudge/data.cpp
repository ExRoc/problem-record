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
    cin.tie(nullptr);
    srand(time(0));

    int N = getRand(1, 5);
    int M = getRand(1, 5);
    cout << N << ' ' << M << '\n';
    for (int i = 1; i < N; ++i) {
        cout << (getRand(0, 1) == 1 ? '<' : '>');
    }
    cout << '\n';
    for (int i = 0; i < M; ++i) {
        int l = getRand(1, N - 1);
        int r = getRand(l, N - 1);
        cout << l << " " << r << '\n';
    }

    return 0;
}
