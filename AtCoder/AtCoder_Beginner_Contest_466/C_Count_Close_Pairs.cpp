#include <bits/stdc++.h>
using namespace std;

bool judge(int l, int r) {
    cout << "? " << l << " " << r << endl;
    string s;
    cin >> s;
    return s == "Yes";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int ans = 0;
    int l;
    int r = 2;
    for (l = 1; l <= N; ++l) {
        r = max(l + 1, r);
        while (r <= N && judge(l, r)) {
            ++r;
        }
        ans += r - l - 1;
    }
    cout << "! " << ans << endl;

    return 0;
}
