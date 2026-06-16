#include <bits/stdc++.h>
using namespace std;

long long solve(const vector<int>& a, int bit, int n) {
    vector<int> next(n, -1);
    int last = -1;
    int first = -1;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (((a[i] >> bit) & 1) == 1) {
            ++cnt;
            if (last == -1) {
                last = i;
                first = i;
            } else {
                next[last] = i;
                last = i;
            }
        }
    }
    if (cnt % 2 == 1) {
        return -1;
    }
    if (last == -1) {
        return 0;
    }
    next[last] = first;
    int ans1 = 0;
    int idx = first;
    do {
        ans1 += (next[idx] - idx + n) % n;
        idx = next[next[idx]];
    } while (idx != first);
    int ans2 = 0;
    idx = next[first];

    do {
        ans2 += (next[idx] - idx + n) % n;
        idx = next[next[idx]];
    } while (idx != next[first]);
    return min(ans1, ans2);
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 0; i < 30; ++i) {
        long long tmp = solve(a, i, n);
        if (tmp == -1) {
            cout << -1 << '\n';
            return 0;
        }
        ans += tmp;
    }
    cout << ans << '\n';

    return 0;
}