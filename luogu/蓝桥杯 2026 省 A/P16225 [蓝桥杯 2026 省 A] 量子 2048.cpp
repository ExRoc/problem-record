#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long LL;

bool canPutZero(int x, int y, int n, vector<int>& row, vector<int>& col,
                vector<vector<int>>& v) {
    if (x == n - 1) {
        if (col[y] == 0) {
            return false;
        }
    }
    if (y == n - 1) {
        if (row[x] == 0) {
            return false;
        }
    }
    if (x != 0 && y != 0) {
        if ((v[x - 1][y - 1] + v[x - 1][y] + v[x][y - 1]) % 2 == 0) {
            return false;
        }
    }
    return true;
}

bool canPutOne(int x, int y, int n, vector<int>& row, vector<int>& col,
               vector<vector<int>>& v) {
    if (x == n - 1) {
        if (col[y] == 1) {
            return false;
        }
    }
    if (y == n - 1) {
        if (row[x] == 1) {
            return false;
        }
    }
    if (x != 0 && y != 0) {
        if ((v[x - 1][y - 1] + v[x - 1][y] + v[x][y - 1]) % 2 == 1) {
            return false;
        }
    }
    return true;
}

void dfs(int depth, int n, int& ans, vector<int>& row, vector<int>& col,
         vector<vector<int>>& v) {
    if (depth == n * n) {
        ++ans;
        return;
    }
    int x = depth / n;
    int y = depth % n;
    if (canPutZero(x, y, n, row, col, v)) {
        dfs(depth + 1, n, ans, row, col, v);
    }
    if (canPutOne(x, y, n, row, col, v)) {
        row[x] ^= 1;
        col[y] ^= 1;
        v[x][y] = 1;
        dfs(depth + 1, n, ans, row, col, v);
        row[x] ^= 1;
        col[y] ^= 1;
        v[x][y] = 0;
    }
}

void solve(int n) {
    vector<vector<int>> v(n, vector<int>(n, 0));
    vector<int> row(n, 0), col(n, 0);
    int ans = 0;
    dfs(0, n, ans, row, col, v);
    cout << "n = " << n << " ans = " << ans << endl;
}

LL fastPow(LL res, LL n, LL MOD) {
    LL ans;
    for (ans = 1; n != 0; n >>= 1) {
        if ((n & 1) == 1) {
            ans = ans * res % MOD;
        }
        res = res * res % MOD;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    // for (int n = 2; n < 15; n++) {
    //     solve(n);
    // }
    cout << fastPow(2, 511 * 8 + 5, 998244353) << endl;

    return 0;
}
