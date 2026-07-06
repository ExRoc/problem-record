#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 1; i < N; ++i) {
            ans += a[i] - a[i - 1] - 1;
        }
        ans = max(ans - (a[1] - a[0] - 1), ans - (a[N - 1] - a[N - 2] - 1));
        cout << ans << '\n';
    }

    return 0;
}