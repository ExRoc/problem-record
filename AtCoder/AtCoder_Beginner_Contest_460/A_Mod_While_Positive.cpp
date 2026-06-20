#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    int ans = 0;
    while (M != 0) {
        M = N % M;
        ++ans;
    }
    cout << ans << '\n';

    return 0;
}