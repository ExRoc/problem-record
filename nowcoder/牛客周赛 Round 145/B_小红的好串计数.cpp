#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    long long ans = 0;
    int r = 0;
    vector<int> cnt(2, 0);
    for (int l = 0; l < n; ++l) {
        while (r < n && cnt[(s[r] - '0') ^ 1] == 0) {
            ++cnt[s[r] - '0'];
            ++r;
        }
        ans += n - r;
        --cnt[s[l] - '0'];
    }
    cout << ans << '\n';

    return 0;
}