#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100 + 100;
int n, m;
string str[maxn];
set<string> s;

void cal(int i, int j) {
    string ss;
    for (int k = 0; k < m; ++k) {
        ss += str[i + k].substr(j, m);
    }
    s.insert(ss);
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }
    for (int i = 0; i <= n - m; ++i) {
        for (int j = 0; j <= n - m; ++j) {
            cal(i, j);
        }
    }
    cout << s.size() << endl;

    return 0;
}
