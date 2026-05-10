#include <bits/stdc++.h>
using namespace std;

bool cmp(long long a, long long b) { return a > b; }

int main() {
    ios::sync_with_stdio(false);

    long long h, w;
    cin >> h >> w;
    int n;
    cin >> n;
    vector<pair<long long, long long>> ab;
    vector<long long> sand;
    for (int i = 0; i < n; ++i) {
        long long a, b;
        cin >> a >> b;
        ab.push_back(make_pair(a, b));
        sand.push_back(a);
    }
    sort(sand.begin(), sand.end());
    sand.erase(unique(sand.begin(), sand.end()), sand.end());
    vector<vector<long long>> G(sand.size());
    for (pair<long long, long long>& p : ab) {
        p.first = lower_bound(sand.begin(), sand.end(), p.first) - sand.begin();
        G[p.first].push_back(p.second);
    }
    long long ans = 0;
    vector<long long> sum;
    long long ansTmp = 0;
    for (vector<long long>& g : G) {
        sort(g.begin(), g.end());
        ans += 2 * (g.back() - 1);
        long long sumTmp = min(g.back() - 1, w - g.front()) * 2;
        if ((int)g.size() > 1) {
            for (int i = 1; i < (int)g.size(); ++i) {
                sumTmp = min(sumTmp, (g[i - 1] - 1 + w - g[i]) * 2);
            }
        }
        sum.push_back(sumTmp);
        ansTmp += sumTmp;
    }
    sort(sum.begin(), sum.end(), cmp);
    for (int i = 0; i + 1 < (int)sum.size(); i += 2) {
        ansTmp -= sum[i] + sum[i + 1];
        ansTmp += (w - 1) * 2;
        ans = min(ans, ansTmp);
    }
    cout << ans << '\n';

    return 0;
}