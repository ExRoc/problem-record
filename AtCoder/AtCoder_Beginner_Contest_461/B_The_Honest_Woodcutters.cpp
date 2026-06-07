#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> Bs(N + 1);
    for (int i = 1; i <= N; ++i) {
        int A;
        cin >> A;
        Bs[A] = i;
    }
    bool flag = true;
    for (int i = 1; i <= N; ++i) {
        int B;
        cin >> B;
        if (Bs[i] != B) {
            flag = false;
            break;
        }
    }
    cout << (flag ? "Yes" : "No") << '\n';

    return 0;
}