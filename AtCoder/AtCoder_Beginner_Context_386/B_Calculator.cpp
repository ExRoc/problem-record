#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1000 + 100;
int ans;
char str[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> str;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '0' && str[i + 1] == '0') {
            ++i;
        }
        ++ans;
    }
    cout << ans << endl;

    return 0;
}
