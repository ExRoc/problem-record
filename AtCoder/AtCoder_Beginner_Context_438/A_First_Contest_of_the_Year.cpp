#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
int D, F;

int main() {
    ios::sync_with_stdio(false);

    cin >> D >> F;
    int tmp = ((D - F + 6) / 7 * 7 + F);
    if (tmp == D) {
        cout << 7 << endl;
    } else {
        cout << tmp - D << endl;
    }

    return 0;
}
