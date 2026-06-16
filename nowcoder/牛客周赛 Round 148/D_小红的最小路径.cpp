
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(false);

    int l, r;
    cin >> l >> r;
    vector<int> ans;
    ans.push_back(l);
    for (int i = 30; i >= 0; --i) {
        if ((((l ^ r) >> i) & 1) == 1) {
            ans.push_back(ans.back() ^ (1 << i));
        }
    }
    cout << ans.size() << endl;
    for (int x : ans) {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}