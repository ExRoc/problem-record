#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int n, k;
LL ans, sum;
pair<int, LL> node[maxn];
priority_queue<LL> que;

int main() {
    ios::sync_with_stdio(false);

    ans = -(0x3f3f3f3f3f3f3f3fLL);
    cin >> n >> k;
    node[0] = make_pair(1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> node[i].first >> node[i].second;
    }
    for (int i = n; i >= 0; --i) {
        if (node[i].first == 1) {
            ans = max(ans, node[i].second + sum);
            --k;
        } else {
            que.push(node[i].second);
        }
        if (k < 0) {
            break;
        }
        while (!que.empty() && (int)que.size() > k) {
            sum += que.top();
            que.pop();
        }
        while (!que.empty() && que.top() >= 0) {
            sum += que.top();
            que.pop();
        }
    }
    cout << ans << endl;

    return 0;
}
