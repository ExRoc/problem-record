#include <bits/stdc++.h>
using namespace std;

int getNext(const vector<int>& ans, int n, int idx) {
    if (idx == (int)ans.size() - 1) {
        idx = 0;
    }
    ++idx;
    while (ans[idx] != n) {
        ++idx;
    }
    return idx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        ans.push_back(n);
    }
    int idx = 0;
    for (int i = n - 1; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
            idx = getNext(ans, n, idx);
            ans.insert(ans.begin() + idx, i);
            ++idx;
        }
    }
    for (int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
