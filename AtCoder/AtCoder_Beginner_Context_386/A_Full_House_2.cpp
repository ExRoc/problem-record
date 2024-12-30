#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100;
int x;
int cnt[maxn], ccnt[maxn];

bool judge() {
    for (int i = 1; i <= 13; ++i) {
        ++ccnt[cnt[i]];
    }
    return ccnt[2] == 2 || (ccnt[3] == 1 && ccnt[1] == 1);
}

int main() {
    ios::sync_with_stdio(false);

    for (int i = 0; i < 4; ++i) {
        cin >> x;
        ++cnt[x];
    }
    cout << (judge() ? "Yes" : "No") << endl;

    return 0;
}
