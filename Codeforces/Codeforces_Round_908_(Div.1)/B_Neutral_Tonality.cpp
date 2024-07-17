#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int T, n, m;
int a[maxn], b[maxn];
map<int, int> idx;
map<int, int>::iterator it;
vector<int> ans[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        idx.clear();
        cin >> n >> m;
        ans[0].clear();
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            idx[a[i]] = i;
            ans[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        sort(b, b + m);
        for (int i = m - 1; i >= 0; --i) {
            it = idx.lower_bound(b[i]);
            if (it == idx.end()) {
                ans[0].push_back(b[i]);
            } else {
                ans[it->second].push_back(b[i]);
            }
        }
        for (int x : ans[0]) {
            cout << x << " ";
        }
        for (int i = 1; i <= n; ++i) {
            cout << a[i] << " ";
            for (int x : ans[i]) {
                cout << x << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
