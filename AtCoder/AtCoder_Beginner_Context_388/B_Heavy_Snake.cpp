#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100 + 100;
int n, d;
int T[maxn], L[maxn];

int solve(int k) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, T[i] * (L[i] + k));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        cin >> T[i] >> L[i];
    }
    for (int i = 1; i <= d; ++i) {
        cout << solve(i) << endl;
    }

    return 0;
}
