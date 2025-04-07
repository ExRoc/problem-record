#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 300000 + 100;
int q, cmd, l, k, head, tail;
LL que[maxn];

int main() {
    ios::sync_with_stdio(false);

    head = tail = 1;
    cin >> q;
    while (q--) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> l;
            que[tail] = que[tail - 1] + l;
            ++tail;
        } else if (cmd == 2) {
            ++head;
        } else if (cmd == 3) {
            cin >> k;
            cout << que[head + k - 2] - que[head - 1] << endl;
        }
    }

    return 0;
}
