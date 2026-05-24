#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int>& c) {
    int a = c[0] + c[1] + c[2];
    if (a % 10 != 0) {
        return 0;
    }
    int b = c[3] + c[4];
    if (b % 10 != 0) {
        return b % 10;
    }
    return 10;
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        vector<int> c(5);
        for (int i = 0; i < 5; ++i) {
            cin >> c[i];
        }
        sort(c.begin(), c.end());
        int ans = 0;
        vector<string> ansStr = {"No Bull", "Bull 1", "Bull 2",   "Bull 3",
                                 "Bull 4",  "Bull 5", "Bull 6",   "Bull 7",
                                 "Bull 8",  "Bull 9", "Bull Bull"};
        do {
            ans = max(ans, solve(c));
        } while (next_permutation(c.begin(), c.end()));
        cout << ansStr[ans] << '\n';
    }

    return 0;
}