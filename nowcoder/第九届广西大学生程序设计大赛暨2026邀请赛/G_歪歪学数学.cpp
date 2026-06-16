#include <bits/stdc++.h>
using namespace std;

bool judge(int n) {
    int sum = 0;
    int prod = 1;
    int nn = n;
    while (n != 0) {
        sum += n % 10;
        prod *= n % 10;
        n /= 10;
    }
    return sum + prod == nn;
}

int main() {
    ios::sync_with_stdio(false);

    vector<int> nums = {19, 29, 39, 49, 59, 69, 79, 89, 99};
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << upper_bound(nums.begin(), nums.end(), n) - nums.begin() << '\n';
    }

    return 0;
}