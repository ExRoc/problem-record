#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; ++i) {
        int U, V;
        cin >> U >> V;
        --U;
        --V;
        G[U].push_back(V);
        G[V].push_back(U);
    }
    string ans;
    for (int i = 0; i < N; ++i) {
        ans += 'A';
    }
    queue<int> que;
    que.push(N - 2);
    ans[N - 2] = 'B';
    while (!que.empty()) {
        int tmp = que.front();
        que.pop();
        for (int pos : G[tmp]) {
            if (pos == N - 1 || ans[pos] == 'B') {
                continue;
            }
            ans[pos] = 'B';
            que.push(pos);
        }
    }
    cout << ans << '\n';

    return 0;
}