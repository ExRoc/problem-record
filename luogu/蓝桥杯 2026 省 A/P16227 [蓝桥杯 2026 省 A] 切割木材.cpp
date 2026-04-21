#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long LL;
const int maxn = 1000000 + 100;
int n, k;
int a[maxn];

bool judge(int L) {
    LL cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += (a[i] + L - 1) / L - 1;
    }
    return cnt <= k;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int low = 0;
    int high = 1000000000;
    int mid;
    while (high - low > 1) {
        mid = (low + high) >> 1;
        if (judge(mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    cout << high << endl;

    return 0;
}
