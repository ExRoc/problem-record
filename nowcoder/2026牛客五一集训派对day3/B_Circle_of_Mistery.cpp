#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> num(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        bool flag = false;
        priority_queue<int> que1;
        priority_queue<int, vector<int>, greater<int>> que2;
        for (int j = i; j <= n; ++j) {
            que1.push(num[j]);
            while (!que1.empty() &&
                   (que1.top() >= 0 || sum + que1.top() >= k)) {
                sum += que1.top();
                que2.push(que1.top());
                que1.pop();
                flag = true;
            }
            if (flag && sum >= k) {
                ans = min(ans, 2 * (j - i + 1) - 1 - (int)que2.size());
                // cout << "i = " << i << " j = " << j
                //      << " ans = " << 2 * (j - i + 1) - 1 - (int)que2.size()
                //      << endl;
            }
        }
    }
    if (ans == INT_MAX) {
        ans = -1;
    }
    cout << ans << '\n';

    return 0;
}