#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> idx(n + 1);
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        idx[a[i]].push_back(i);
        if ((int)idx[a[i]].size() > 2) {
            flag = false;
            break;
        }
    }
    if (!flag) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> b(n, 0), c(n, 0);
    set<int> setb;
    for (int i = 1; i <= n; ++i) {
        setb.insert(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (idx[i].size() == 2) {
            b[idx[i][0]] = i;
            c[idx[i][1]] = i;
            setb.erase(i);
            continue;
        }
        if ((int)idx[i].size() == 1) {
            b[idx[i][0]] = c[idx[i][0]] = i;
            setb.erase(i);
        }
    }
    set<int> setc = setb;
    for (int i = 0; i < n; ++i) {
        if (b[i] == 0) {
            b[i] = *setb.begin();
            setb.erase(setb.begin());
        }
        if (c[i] == 0) {
            c[i] = *setc.begin();
            setc.erase(setc.begin());
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << b[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; ++i) {
        cout << c[i] << ' ';
    }
    cout << '\n';

    return 0;
}