#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1000 + 100;
int n;
int p[10];
char ans[maxn][maxn];

void dfs(int n, int x, int y) {
    if (n == 0) {
        ans[x][y] = '#';
        return;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == 1 && j == 1) {
                continue;
            }
            int xx = x + p[n - 1] * i;
            int yy = y + p[n - 1] * j;
            dfs(n - 1, xx, yy);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    p[0] = 1;
    for (int i = 1; i <= 6; ++i) {
        p[i] = p[i - 1] * 3;
    }
    cin >> n;
    for (int i = 0; i < p[n]; ++i) {
        memset(ans[i], '.', sizeof(char) * p[n]);
    }
    dfs(n, 0, 0);
    for (int i = 0; i < p[n]; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}
