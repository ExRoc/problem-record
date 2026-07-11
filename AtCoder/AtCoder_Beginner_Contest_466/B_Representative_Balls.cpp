#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> ans(M + 1, -1);
    for (int i = 0; i < N; ++i) {
        int C, S;
        cin >> C >> S;
        ans[C] = max(ans[C], S);
    }
    for (int i = 1; i <= M; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}