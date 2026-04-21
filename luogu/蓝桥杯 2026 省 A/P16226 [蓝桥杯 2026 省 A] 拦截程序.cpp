#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long LL;
const int maxn = 1000000 + 100;
int C;
LL L, V, T;

int main() {
    ios::sync_with_stdio(false);

    cin >> C;
    while (C--) {
        cin >> L >> V >> T;
        LL Pa = V * T;
        LL Pb = L - V * T;
        LL mid = (Pa + Pb) / 2;
        cout << max(abs(mid - Pa), abs(mid - Pb)) << endl;
    }

    return 0;
}
