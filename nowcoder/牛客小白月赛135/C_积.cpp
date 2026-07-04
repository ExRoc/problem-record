#include <bits/stdc++.h>
using namespace std;

int solve9(int n, const vector<int>& a) {
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, (9 - a[i] % 9) % 9);
    }
    return ans;
}

int solve33(int n, const vector<int>& a) {
    if (n == 1) {
        return INT_MAX;
    }
    vector<int> tmp;
    for (int i = 0; i < n; ++i) {
        tmp.push_back((3 - a[i] % 3) % 3);
    }
    sort(tmp.begin(), tmp.end());
    return tmp[0] + tmp[1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << min(solve9(n, a), solve33(n, a)) << '\n';
    }

    return 0;
}