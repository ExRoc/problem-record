#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;
    vector<int> ans(N);
    int d = -1;
    int L = 0;
    int R = N - 1;
    int num = N;
    for (int i = N - 1; i >= 0; --i) {
        if (S[i] == 'o') {
            d = -d;
        }
        if (d == 1) {
            ans[L++] = num--;
        } else {
            ans[R--] = num--;
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}