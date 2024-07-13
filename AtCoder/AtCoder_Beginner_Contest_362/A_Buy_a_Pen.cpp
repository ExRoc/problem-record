#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
int ans;
int num[3];
string s;
string str[3] = {"Red", "Green", "Blue"};

int main() {
    ios::sync_with_stdio(false);

    for (int i = 0; i < 3; ++i) {
        cin >> num[i];
    }
    cin >> s;
    ans = 100;
    for (int i = 0; i < 3; ++i) {
        if (s == str[i]) {
            continue;
        }
        ans = min(ans, num[i]);
    }
    cout << ans << endl;

    return 0;
}
