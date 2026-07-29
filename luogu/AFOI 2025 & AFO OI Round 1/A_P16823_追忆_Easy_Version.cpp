#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if (n == 2) {
        cout << "! 1" << endl;
        return 0;
    }
    int idx = -1;
    for (int i = 2; i < n; ++i) {
        cout << "? 1 " << i << endl;
        int dis;
        cin >> dis;
        if (dis == 1) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << "! 1" << endl;
        return 0;
    }
    cout << "? " << idx << " " << n << endl;
    int dis;
    cin >> dis;
    cout << "! " << dis << '\n';

    return 0;
}