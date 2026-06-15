#include <bits/stdc++.h>
using namespace std;

long long preSolve(vector<long long> left, long long score,
                   const vector<long long> cnt) {
    for (int i = 0; i < 13; ++i) {
        if (cnt[i] < left[i]) {
            return -1;
        }
    }
    long long ans = 0;
    for (int i = 0; i < 11; ++i) {
        long long tmp = min({left[i], left[i + 1], left[i + 2]});
        left[i] -= tmp;
        left[i + 1] -= tmp;
        left[i + 2] -= tmp;
        ans += score * tmp;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    long long n, a, b;
    cin >> n >> a >> b;
    vector<long long> cnt(13, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[x - 1];
    }
    vector<long long> pow3(12);
    pow3[0] = 1;
    for (int i = 1; i < 12; ++i) {
        pow3[i] = pow3[i - 1] * 3;
    }
    long long ans = 0;
    for (int status = 0; status < pow3[11]; ++status) {
        vector<long long> left(13, 0);
        for (int j = 0; j < 11; ++j) {
            long long tmp = status / pow3[j] % 3;
            left[j] += tmp;
            left[j + 1] += tmp;
            left[j + 2] += tmp;
        }
        long long ansTmp = preSolve(left, b, cnt);
        if (ansTmp == -1) {
            continue;
        }
        vector<long long> cntTmp = cnt;
        for (int j = 0; j < 13; ++j) {
            cntTmp[j] -= left[j];
        }
        for (int j = 0; j < 11; ++j) {
            long long tmp =
                min({cntTmp[j] / 3, cntTmp[j + 1] / 3, cntTmp[j + 2] / 3});
            ansTmp += tmp * max(a, b) * 3;
            cntTmp[j] -= 3 * tmp;
            cntTmp[j + 1] -= 3 * tmp;
            cntTmp[j + 2] -= 3 * tmp;
        }
        for (int j = 0; j < 13; ++j) {
            ansTmp += cntTmp[j] / 3 * a;
        }
        ans = max(ans, ansTmp);
    }
    cout << ans << '\n';

    return 0;
}