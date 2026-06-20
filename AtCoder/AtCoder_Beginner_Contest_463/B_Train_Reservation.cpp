#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N;
    char X;
    cin >> N >> X;
    bool flag = false;
    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S;
        if (S[X - 'A'] == 'o') {
            flag = true;
        }
    }
    cout << (flag ? "Yes" : "No") << '\n';

    return 0;
}