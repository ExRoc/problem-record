#include <bits/stdc++.h>
using namespace std;

void output(vector<long long> Xs) {
    int n = Xs.size();
    sort(Xs.begin(), Xs.end());
    if (n % 2 == 0) {
        long long ans = Xs[n / 2] + Xs[n / 2 - 1];
        cout << ans / 2 << (ans % 2 == 0 ? ".0000000000" : ".5000000000")
             << '\n';
        return;
    }
    long long ans = Xs[n / 2];
    cout << ans << ".0000000000" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<long long> Xs(n);
    for (int i = 0; i < n; ++i) {
        cin >> Xs[i];
    }
    output(Xs);
    for (int i = 0; i < m; ++i) {
        int op;
        long long K;
        cin >> op >> K;
        if (op == 1) {
            Xs.push_back(K);
            ++n;
        } else if (op == 2) {
            for (int j = 0; j < n; ++j) {
                Xs[j] += K;
            }
        } else {
            for (int j = 0; j < n; ++j) {
                Xs[j] = K * 2 - Xs[j];
            }
        }
        output(Xs);
    }

    return 0;
}