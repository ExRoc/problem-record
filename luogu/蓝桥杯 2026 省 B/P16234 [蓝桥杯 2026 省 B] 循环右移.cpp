#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long LL;
const int maxn = 1000000 + 100;
int T;
LL N, X, Y;

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> N >> X >> Y;
        cout << max(0LL, Y - X + 1) << endl;
    }

    return 0;
}
