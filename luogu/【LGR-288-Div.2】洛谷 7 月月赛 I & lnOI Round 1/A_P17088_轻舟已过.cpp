#include <bits/stdc++.h>
using namespace std;

long long lowbit(long long x) { return x & -x; }

long long solve(int n, int k) {
    long long ans = (1LL << k);
    --k;
    if (k == 0) {
        return ans;
    }
    for (int i = n - 1; i >= 0; --i) {
        ans |= (1LL << i);
        --k;
        if (k == 0) {
            return ans;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int k = n; k > 0; --k) {
        long long ans = solve(n, k);
        if (lowbit(ans) == (1LL << k) && __builtin_popcountll(ans) == k) {
            cout << ans << '\n';
            return 0;
        }
    }

    return 0;
}