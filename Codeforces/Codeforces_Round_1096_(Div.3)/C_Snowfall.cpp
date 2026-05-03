#include <bits/stdc++.h>
using namespace std;

int getNum(int x) {
    if (x % 6 == 0) {
        return 5;
    }
    if (x % 3 == 0) {
        return 4;
    }
    if (x % 2 == 0) {
        return -1;
    }
    return 0;
}

bool cmp(int a, int b) {
    int aa = getNum(a);
    int bb = getNum(b);
    return aa == bb ? a < b : aa < bb;
}

int main() {
    ios::sync_with_stdio(false);

    int T, n, x;
    vector<int> num;
    cin >> T;
    while (T--) {
        cin >> n;
        num.clear();
        for (int i = 0; i < n; ++i) {
            cin >> x;
            num.push_back(x);
        }
        sort(num.begin(), num.end(), cmp);
        for (int x : num) {
            cout << x << " ";
        }
        cout << '\n';
    }

    return 0;
}
