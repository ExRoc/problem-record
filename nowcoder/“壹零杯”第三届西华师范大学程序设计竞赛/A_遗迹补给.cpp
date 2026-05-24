#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N, X;
    cin >> N >> X;
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        if (A > X) {
            ans += A;
        }
    }
    cout << ans << '\n';

    return 0;
}