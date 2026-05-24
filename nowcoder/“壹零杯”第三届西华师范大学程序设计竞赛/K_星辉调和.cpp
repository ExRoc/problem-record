#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> cnt(2);
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        ++cnt[A & 1];
    }
    cout << min(cnt[0], cnt[1]) << '\n';

    return 0;
}