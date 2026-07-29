#include <bits/stdc++.h>
using namespace std;

int id(char ch) { return ch - 'a' + 1; }

void solve15(int n, int m, const vector<string>& Ss, const vector<string>& Ts) {
    set<long long> hashCodeSet;
    const long long MOD = 1e9 + 7;
    for (const string& S : Ss) {
        int len = S.length();
        long long hashCode = 0;
        for (char ch : S) {
            hashCode = (hashCode * 26 + id(ch)) % MOD;
            hashCodeSet.insert(hashCode);
        }
        hashCode = 0;
        long long p = 1;
        for (int i = len - 1; i >= 0; --i) {
            hashCode = (hashCode + id(S[i]) * p) % MOD;
            p = p * 26 % MOD;
            hashCodeSet.insert(hashCode);
        }
    }
    const int e6 = 1e6;
    vector<long long> p(e6 + 1);
    p[0] = 1;
    for (int i = 1; i <= e6; ++i) {
        p[i] = p[i - 1] * 26 % MOD;
    }
    for (const string& T : Ts) {
        int len = T.length();
        vector<long long> hashCodeT(len);
        long long hashCode = 0;
        for (int i = 0; i < len; ++i) {
            hashCode = (hashCode * 26 + id(T[i])) % MOD;
            hashCodeT[i] = hashCode;
        }
        int ans = 0;
        for (int idx1 = 1; idx1 < len; ++idx1) {
            for (int idx2 = idx1 + 1; idx2 < len; ++idx2) {
                // [0, idx1 - 1] [idx1, idx2 - 1] [idx2, len - 1]
                long long hashCode1 = hashCodeT[idx1 - 1];
                long long hashCode2 =
                    (hashCodeT[idx2 - 1] -
                     hashCodeT[idx1 - 1] * p[idx2 - idx1] % MOD) %
                    MOD;
                long long hashCode3 =
                    (hashCodeT[len - 1] -
                     hashCodeT[idx2 - 1] * p[len - idx2] % MOD) %
                    MOD;
                if (hashCodeSet.find(hashCode1) != hashCodeSet.end() &&
                    hashCodeSet.find(hashCode2) != hashCodeSet.end() &&
                    hashCodeSet.find(hashCode3) != hashCodeSet.end()) {
                    ++ans;
                }
            }
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> Ss(n);
    for (int i = 0; i < n; ++i) {
        cin >> Ss[i];
    }
    vector<string> Ts(m);
    for (int i = 0; i < m; ++i) {
        cin >> Ts[i];
    }
    solve15(n, m, Ss, Ts);

    return 0;
}