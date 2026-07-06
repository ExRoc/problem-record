#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    long long ans = 0;
    priority_queue<int> que;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (s[i] == '(') {
            que.push(a);
            continue;
        }
        if (!que.empty() && que.top() + a >= 0) {
            ans += que.top() + a;
            que.pop();
            que.push(-a);
        }
    }
    cout << ans << '\n';

    return 0;
}