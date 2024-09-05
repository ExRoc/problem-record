#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int INF = 1000000009;
int T;
int cnt[2];
vector<vector<int>> nums[2];

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> cnt[0] >> cnt[1];
        for (int i = 0; i < 2; ++i) {
            nums[i].assign(2, vector<int>(2, INF));
            for (int j = 0; j < cnt[i] + 1; ++j) {
                if (j == 1) {
                    continue;
                }
                cin >> nums[i][j / 2][j & 1];
                if (j == 0) {
                    nums[i][j / 2][j & 1] += 2;
                }
                if (j == 2) {
                    nums[i][j / 2][j & 1] += 1;
                }
            }
            for (int j = 0; j < 2; ++j) {
                sort(nums[i][j].begin(), nums[i][j].end());
            }
            sort(nums[i].begin(), nums[i].end());
        }
        if (nums[0] < nums[1]) {
            cout << 1 << endl;
        } else if (nums[0] > nums[1]) {
            cout << -1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}
