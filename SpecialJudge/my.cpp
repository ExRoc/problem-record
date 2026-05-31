#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                ++cnt;
            }
        }
        int ans = cnt;
        for (int i = 0; i < cnt; ++i) {
            if (nums[n - i - 1] == 0) {
                --ans;
            }
        }
        cout << ans - 1 << '\n';
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);

    return 0;
}
