#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
int n, ans;
string str, t = "Takahashi";

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    while (n--) {
        cin >> str;
        if (str == t) {
            ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}
