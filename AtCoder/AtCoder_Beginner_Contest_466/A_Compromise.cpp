#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    bool allNeg = true;
    for (int i = 0; i < N; ++i) {
        int X;
        cin >> X;
        if (X >= 0) {
            allNeg = false;
        }
    }
    if (allNeg) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }

    return 0;
}