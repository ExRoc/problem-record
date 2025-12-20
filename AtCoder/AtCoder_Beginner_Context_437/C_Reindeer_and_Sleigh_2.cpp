#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 300000 + 100;
struct Node {
    LL p, w;
};

bool operator<(const Node& a, const Node& b) {
    return a.p + a.w > b.p + b.w;
}

int T, n, ans;
LL tmp;
Node node[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n;
        tmp = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> node[i].w >> node[i].p;
            tmp += node[i].w;
        }
        sort(node + 1, node + 1 + n);
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            tmp = tmp - node[i].w - node[i].p;
            if (tmp <= 0) {
                ans = n - i;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
