#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int n;
LL ans;
int a[maxn];
int fa[maxn];
LL num[maxn], degin[maxn], dp[maxn];
bool inC[maxn], vis[maxn];
queue<int> que;

void init() {
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        num[i] = 1;
    }
}

int Find(int x) {
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

void unit(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x != y) {
        fa[x] = y;
        num[y] += num[x];
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    init();
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (Find(i) == Find(a[i])) {
            inC[i] = true;
        }
        unit(i, a[i]);
        ++degin[a[i]];
    }
    init();
    for (int i = 1; i <= n; ++i) {
        if (inC[i]) {
            vis[i] = true;
            int pos = a[i];
            unit(i, pos);
            while (pos != i) {
                vis[pos] = true;
                unit(pos, a[pos]);
                pos = a[pos];
            }
            ans += num[Find(i)] * num[Find(i)];
        }
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (degin[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int tmp = que.front();
        que.pop();
        ans += dp[tmp];
        int pos = a[tmp];
        if (vis[pos]) {
            ans += dp[tmp] * num[Find(pos)];
            continue;
        }
        dp[pos] += dp[tmp];
        --degin[pos];
        if (degin[pos] == 0) {
            que.push(pos);
        }
    }
    cout << ans << endl;

    return 0;
}
