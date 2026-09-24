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
    vector<long long> c(N + 1), v(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> c[i] >> v[i];
        c[i] += c[i - 1];
        v[i] += v[i - 1];
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int n;
        cin >> n;
        if (c[n] - v[n] < 0) {
            cout << "VENDA" << '\n';
        } else if (c[n] - v[n] > 0) {
            cout << "COMPRA" << '\n';
        } else {
            cout << "NEUTRO" << '\n';
        }
    }

    return 0;
}