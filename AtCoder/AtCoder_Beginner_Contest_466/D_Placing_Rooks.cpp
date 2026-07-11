#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> row(N + 1), col(N + 1);
    for (int i = 1; i <= M; ++i) {
        int R, C;
        cin >> R >> C;
        row[R].clear();
        col[C].clear();
        row[R].push_back(i);
        col[C].push_back(i);
    }
    set<int> rowSet, colSet;
    for (int i = 1; i <= N; ++i) {
        for (int rIdx : row[i]) {
            rowSet.insert(rIdx);
        }
        for (int cIdx : col[i]) {
            colSet.insert(cIdx);
        }
    }
    int ans = 0;
    for (int i = 1; i <= M; ++i) {
        if (rowSet.find(i) != rowSet.end() && colSet.find(i) != colSet.end()) {
            ++ans;
        }
    }
    cout << ans << '\n';

    return 0;
}