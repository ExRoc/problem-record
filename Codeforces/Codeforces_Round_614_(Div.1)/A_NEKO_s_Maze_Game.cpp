#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
int n, q, r, c;
bool flag[2][maxn];
set<pair<int, int>> st;

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> q;
    while (q--) {
        cin >> r >> c;
        --r;
        flag[r][c] = !flag[r][c];
        for (int i = -1; i <= 1; ++i) {
            if (flag[r ^ 1][i + c]) {
                pair<int, int> p;
                if (r == 0) {
                    p = {c, i + c};
                } else {
                    p = {i + c, c};
                }
                if (flag[r][c]) {
                    st.insert(p);
                } else {
                    st.erase(p);
                }
            }
        }
        if (st.empty()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
