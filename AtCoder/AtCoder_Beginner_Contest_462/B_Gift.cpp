#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<vector<int>> B(N + 1, vector<int>());
    for (int i = 1; i <= N; ++i) {
        int K;
        cin >> K;
        for (int j = 0; j < K; ++j) {
            int A;
            cin >> A;
            B[A].push_back(i);
        }
    }
    for (int i = 1; i <= N; ++i) {
        cout << B[i].size();
        for (int b : B[i]) {
            cout << " " << b;
        }
        cout << '\n';
    }

    return 0;
}