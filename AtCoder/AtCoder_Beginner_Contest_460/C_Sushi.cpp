#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int idx = 0;
    int ans = 0;
    for (int i = 0; i < M; ++i) {
        while (idx < N && A[idx] * 2 < B[i]) {
            ++idx;
        }
        if (idx < N) {
            ++ans;
            ++idx;
        }
    }
    cout << ans << '\n';

    return 0;
}