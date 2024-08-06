#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long long LL;
const int maxn = 200000 + 100;
int n, top;
LL ans;
LL num[maxn];
LL sta[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
        while (top > 0 && num[i] >= num[sta[top - 1]]) {
            --top;
            if (top == 0) {
                ans = 0;
            } else {
                ans -= (sta[top] - sta[top - 1]) * num[sta[top]];
            }
        }
        sta[top++] = i;
        if (top == 1) {
            ans = num[i] * i;
        } else {
            ans += (sta[top - 1] - sta[top - 2]) * num[i];
        }
        cout << ans + 1 << " ";
    }
    cout << endl;

    return 0;
}
