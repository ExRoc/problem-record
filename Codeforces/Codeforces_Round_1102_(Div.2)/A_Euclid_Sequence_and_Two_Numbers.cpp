#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        vector<int> tmp(n);
        tmp[0] = b[n - 1];
        tmp[1] = b[n - 2];
        bool flag = true;
        for (int i = 2; i < n; ++i) {
            if (tmp[i - 1] == 0) {
                flag = false;
                break;
            }
            tmp[i] = tmp[i - 2] % tmp[i - 1];
        }
        if (!flag) {
            cout << -1 << '\n';
            continue;
        }
        sort(tmp.begin(), tmp.end());
        if (tmp == b) {
            cout << b[n - 1] << " " << b[n - 2] << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}