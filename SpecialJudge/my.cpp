#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int T, n, a, b;
LL k, ans, tmp;
map<int, LL> mp, mmp;
map<int, LL>::iterator it;
vector<pair<int, LL>> vct;

bool cmp(const pair<int, LL>& a, const pair<int, LL>& b) {
    return a.second > b.second;
}

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        mp.clear();
        mmp.clear();
        vct.clear();
        cin >> n >> k;
        --k;
        for (int i = 1; i <= n; ++i) {
            cin >> a >> b;
            mp[a] += b;
        }
        tmp = 0;
        for (it = mp.begin(); it != mp.end(); ++it) {
            tmp += it->second / 3;
            vct.push_back(*it);
        }
        if (tmp < k) {
            cout << -1 << endl;
            continue;
        }
        sort(vct.begin(), vct.end(), cmp);
        for (pair<int, LL> p : vct) {
            tmp = min(p.second / 3, k);
            mmp[p.first] = min(tmp * 3 + 2, p.second);
            k -= tmp;
        }
        ans = 1;
        for (it = mmp.begin(); it != mmp.end(); ++it) {
            ans += it->second;
        }
        cout << ans << endl;
    }

    return 0;
}
