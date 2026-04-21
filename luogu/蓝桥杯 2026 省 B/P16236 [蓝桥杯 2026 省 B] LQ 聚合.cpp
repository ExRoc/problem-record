#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long LL;
const int maxn = 100000 + 100;
int n;
LL cntL, cntQ, ans, tmp;
string str;

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> str;
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'L') {
            ++cntL;
        } else {
            tmp += cntL;
            ++cntQ;
        }
    }
    ans = tmp;
    cntL = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'L') {
            ++cntL;
        } else if (str[i] == 'Q') {
            --cntQ;
        } else {
            --cntQ;
            tmp = tmp - cntL + cntQ;
            ans = max(ans, tmp);
            ++cntL;
        }
    }
    cout << ans << endl;

    return 0;
}
