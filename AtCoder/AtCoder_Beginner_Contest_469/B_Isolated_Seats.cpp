#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string S;
    cin >> S;
    S = 'x' + S + 'x';
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (S[i - 1] == 'x' && S[i] == 'x' && S[i + 1] == 'x') {
            ++ans;
        }
    }
    cout << ans << '\n';

    return 0;
}