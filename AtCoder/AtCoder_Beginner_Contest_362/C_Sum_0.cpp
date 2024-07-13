#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int n;
LL suml, sumr;
LL l[maxn], r[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        suml += l[i];
        sumr += r[i];
    }
    if (!(suml <= 0 && sumr >= 0)) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; ++i) {
        if (suml + r[i] - l[i] <= 0) {
            suml += r[i] - l[i];
            cout << r[i] << " ";
        } else {
            cout << l[i] - suml << " ";
            suml = 0;
        }
    }
    cout << endl;

    return 0;
}
