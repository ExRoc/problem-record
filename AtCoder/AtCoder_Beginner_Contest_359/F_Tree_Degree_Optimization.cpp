#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
struct Node {
    LL val, dd;
    LL d, num;

    Node() {}

    Node(LL val, LL d, LL num, LL dd) : val(val), d(d), num(num), dd(dd) {}
};

bool operator<(const Node& a, const Node& b) {
    return a.dd > b.dd;
}

int n;
LL a, ans;
priority_queue<Node> que;

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        que.push(Node(a, 1, a, 3 * a));
    }
    for (int i = 0; i < n - 2; ++i) {
        Node tmp = que.top();
        que.pop();
        ++tmp.d;
        tmp.val = tmp.num * tmp.d * tmp.d;
        tmp.dd = tmp.num * ((tmp.d + 1) * (tmp.d + 1) - tmp.d * tmp.d);
        que.push(tmp);
    }
    while (!que.empty()) {
        Node tmp = que.top();
        que.pop();
        ans += tmp.val;
    }
    cout << ans << endl;

    return 0;
}
