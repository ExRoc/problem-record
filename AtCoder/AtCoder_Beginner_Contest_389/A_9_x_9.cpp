#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
string str;

int main() {
    ios::sync_with_stdio(false);

    cin >> str;
    cout << (str[0] - '0') * (str[2] - '0') << endl;

    return 0;
}
