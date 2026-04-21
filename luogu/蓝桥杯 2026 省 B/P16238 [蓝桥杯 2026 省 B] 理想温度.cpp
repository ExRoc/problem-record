#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long LL;
const int maxn = 200000 + 100;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        a[i] -= b[i];
    }

    map<int, vector<int>> idxs;
    vector<int> leq(n + 2, 0), req(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        idxs[a[i]].push_back(i);
        leq[i] = leq[i - 1];
        if (a[i] == 0) {
            ++leq[i];
        }
    }
    for (int i = n; i >= 1; --i) {
        req[i] = req[i + 1];
        if (a[i] == 0) {
            ++req[i];
        }
    }

    int ans = leq[n];
    vector<int> suffixMax;
    for (const auto& [d, idxList] : idxs) {
        suffixMax.assign(idxList.size() + 1, 0);
        for (int i = idxList.size() - 1; i >= 0; --i) {
            int idx = idxList[i];
            suffixMax[i] = max(suffixMax[i + 1], i + 1 + req[idx + 1]);
        }
        for (int i = 0; i < (int)idxList.size(); ++i) {
            int idx = idxList[i];
            ans = max(ans, leq[idx - 1] + suffixMax[i] - i);
        }
    }
    cout << ans << endl;

    return 0;
}
