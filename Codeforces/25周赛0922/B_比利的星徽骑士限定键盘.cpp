#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, C, K;
    cin >> T >> C >> K;
    cout << min(K * T, C) << '\n';

    return 0;
}