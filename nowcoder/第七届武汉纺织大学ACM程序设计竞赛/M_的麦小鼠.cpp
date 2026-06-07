#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, A, B;
    cin >> n >> A >> B;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int a, b, v;
        cin >> a >> b >> v;
        if (B > b) {
            ans += v;
            continue;
        }
        if (B == b) {
            if (A >= a) {
                ans += v;
                continue;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}