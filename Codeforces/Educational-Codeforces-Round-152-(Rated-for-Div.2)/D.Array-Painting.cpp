#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int n, ans, mx;
int num[maxn];
bool vis[maxn];

int findNext(int idx) {
    mx = 0;
    while (num[idx] != 0) {
        mx = max(mx, num[idx]);
        ++idx;
    }
    return idx;
}

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif // ExRoc
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
    }
    for (int i = 1; i <= n; ++i) {
        ++ans;
        if (num[i] == 0)  {
            if (num[i + 1] == 0) {
                continue;
            } else {
                int idx = findNext(i + 1);
                if (mx == 2) {
                    i = idx;
                } else {
                    i = idx - 1;
                }
            }
        } else {
            int idx = findNext(i);
            i = idx;
        }
    }
    cout << ans << endl;

    return 0;
}