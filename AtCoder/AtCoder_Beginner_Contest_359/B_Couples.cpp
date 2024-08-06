#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int n, ans;
int num[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= 2 * n; ++i) {
        cin >> num[i];
        if (i >= 3 && num[i] == num[i - 2]) {
            ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}
