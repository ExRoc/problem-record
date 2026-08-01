#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int d = 1;
    for (int i = 0; i < S.length(); ++i) {
        int begin, end;
        if (d == 1) {
            begin = 0;
            end = S.length() - i;
        } else {
            begin = S.length() - 1;
            end = i - 1;
        }
        for (int j = begin; j != end; j += d) {
            cout << S[j];
        }
        d = -d;
    }
    cout << '\n';

    return 0;
}