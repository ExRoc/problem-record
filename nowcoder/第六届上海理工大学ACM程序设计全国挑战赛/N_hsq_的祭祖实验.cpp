#include <bits/stdc++.h>
using namespace std;

int solve(int n, const string S) {
    vector<int> nums;
    int tmp = 0;
    for (int i = 0; i < 4 * n; ++i) {
        tmp = tmp << 1 | (S[i] - '0');
        if (i % 4 == 3) {
            nums.push_back(tmp);
            tmp = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        nums.push_back(nums[i]);
    }
    int ans = 0;
    vector<int> last120(2 * n);
    for (int i = 2; i < 2 * n; ++i) {
        last120[i] = last120[i - 1];
        if (nums[i - 2] == 1 && nums[i - 1] == 2 && nums[i] == 0) {
            last120[i] = i - 2;
        }
        if (i >= n) {
            if (last120[i] >= i - n + 1) {
                ++ans;
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string S;
        cin >> S;
        int ans = solve(n, S);
        char ch = S[0];
        S = S.substr(1, S.length());
        S.push_back(ch);
        ans += solve(n, S);
        ch = S[0];
        S = S.substr(1, S.length());
        S.push_back(ch);
        ans += solve(n, S);
        ch = S[0];
        S = S.substr(1, S.length());
        S.push_back(ch);
        ans += solve(n, S);
        cout << ans << '\n';
    }

    return 0;
}