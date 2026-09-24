#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> C(N), K(N);
    int sum = 0;
    int mn = 0;
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
        sum += C[i];
        mn = max(mn, C[i]);
    }
    for (int i = 0; i < N; ++i) {
        cin >> K[i];
        if (K[i] > C[i]) {
            cout << -1 << '\n';
            return 0;
        }
        mn = min(mn, C[i] - K[i]);
    }
    cout << sum - mn << '\n';

    return 0;
}