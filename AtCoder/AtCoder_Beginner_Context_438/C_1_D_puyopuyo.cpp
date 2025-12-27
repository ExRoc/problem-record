#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int n, top;
int num[maxn], sta[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
        if (top >= 3 && sta[top - 1] == num[i] && sta[top - 2] == num[i] &&
            sta[top - 3] == num[i]) {
            top -= 3;
        } else {
            sta[top++] = num[i];
        }
    }
    cout << top << endl;

    return 0;
}
