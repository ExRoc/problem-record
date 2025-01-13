#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 500000 + 100;
int n;
int num[maxn];

bool judge(int k) {
    for (int i = 0; i < k; ++i) {
        if (num[n - i] < num[k - i] * 2) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
    }
    int high = n / 2 + 1;
    int low = 0;
    int mid;
    while (high - low > 1) {
        mid = (high + low) >> 1;
        if (judge(mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    cout << low << endl;

    return 0;
}
