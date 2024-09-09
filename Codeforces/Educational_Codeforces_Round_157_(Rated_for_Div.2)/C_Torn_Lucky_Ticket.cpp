#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int n;
LL ans;
string str[maxn];
map<int, int> cnt1[20], cnt2[20];

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
        for (int j = 1; j <= 5; ++j) {
            int len = j + str[i].length();
            if (len % 2 != 0) {
                continue;
            }
            int mid = len / 2;
            int sum = 0;
            for (int k = 0; k < str[i].length(); ++k) {
                if (k < mid) {
                    sum += str[i][str[i].length() - k - 1] - '0';
                } else {
                    sum -= str[i][str[i].length() - k - 1] - '0';
                }
            }
            if (str[i].length() >= mid) {
                ++cnt1[j][sum];
            }
        }
        int sum = 0;
        for (char ch : str[i]) {
            sum += ch - '0';
        }
        ++cnt2[str[i].length()][sum];
    }
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (char ch : str[i]) {
            sum += ch - '0';
        }
        ans += cnt1[str[i].length()][sum];
        for (int j = 1; j < str[i].length(); ++j) {
            int len = j + str[i].length();
            if (len % 2 != 0) {
                continue;
            }
            int mid = (j + str[i].length()) / 2;
            int sum = 0;
            for (int k = 0; k < str[i].length(); ++k) {
                if (k < mid) {
                    sum += str[i][k] - '0';
                } else {
                    sum -= str[i][k] - '0';
                }
            }
            ans += cnt2[j][sum];
        }
    }
    cout << ans << endl;

    return 0;
}
