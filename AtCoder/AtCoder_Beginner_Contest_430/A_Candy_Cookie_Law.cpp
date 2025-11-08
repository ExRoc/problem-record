#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
int a, b, c, d;

int main() {
    ios::sync_with_stdio(false);

    cin >> a >> b >> c >> d;
    if (c >= a) {
        if (d >= b) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    } else {
        cout << "No" << endl;
    }

    return 0;
}
