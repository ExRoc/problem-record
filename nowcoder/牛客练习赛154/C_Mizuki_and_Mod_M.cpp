#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        int K, M;
        cin >> K >> M;
        vector<string> Ps(10);
        for (int i = 0; i < 10; ++i) {
            cin >> Ps[i];
        }
        vector<vector<pair<long long, long long>>> numsP(
            10, vector<pair<long long, long long>>(K + 1));
        for (int i = 0; i < 10; ++i) {
            numsP[i][0] = {i % M, 10};
        }
        for (int i = 1; i <= K; ++i) {
            for (int j = 0; j < 10; ++j) {
                long long tmp = 0;
                long long ten = 1;
                for (char ch : Ps[j]) {
                    int x = ch - '0';
                    tmp = (tmp * numsP[x][i - 1].second % M +
                           numsP[x][i - 1].first) %
                          M;
                    ten = (ten * numsP[x][i - 1].second) % M;
                }
                numsP[j][i] = {tmp, ten};
            }
        }
        long long ans = 0;
        for (char ch : S) {
            int x = ch - '0';
            ans = (ans * numsP[x][K].second % M + numsP[x][K].first) % M;
        }
        cout << ans << '\n';
    }

    return 0;
}