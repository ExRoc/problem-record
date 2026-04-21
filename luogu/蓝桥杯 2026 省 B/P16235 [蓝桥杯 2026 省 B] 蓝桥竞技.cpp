#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long LL;
const int maxn = 100000 + 100;
int T, n;
LL sum, avg;
LL a[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n;
        sum = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum == 0) {
            cout << "T" << endl;
            continue;
        }
        if (n < 5) {
            cout << "F" << endl;
            continue;
        }
        if (sum % 5 != 0) {
            cout << "F" << endl;
            continue;
        }
        avg = sum / 5;
        bool flag = true;
        for (int i = 1; i <= n; ++i) {
            if (a[i] > avg) {
                flag = false;
                break;
            }
        }
        cout << (flag ? "T" : "F") << endl;
    }

    return 0;
}
