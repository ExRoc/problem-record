#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, int> cnts;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            ++cnts[a];
        }
        bool ans = false;
        map<int, int>::reverse_iterator rit;
        for (rit = cnts.rbegin(); rit != cnts.rend(); ++rit) {
            if (rit->second % 2 == 1) {
                ans = true;
                break;
            }
        }
        cout << (ans ? "red" : "fang") << '\n';
    }

    return 0;
}