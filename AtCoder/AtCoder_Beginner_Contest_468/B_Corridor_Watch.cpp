#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, D;
    cin >> M >> D;
    string S;
    cin >> S;
    int ans = 0;
    for (int i = 0; i < M; ++i) {
        bool flag = false;
        for (int j = -D; j <= D; ++j) {
            if (i + j >= 0 && i + j < M && S[i + j] == 'G') {
                flag = true;
            }
        }
        if (!flag) {
            ++ans;
        }
    }
    cout << ans << '\n';

    return 0;
}