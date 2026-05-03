#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T, n;
    vector<int> num;
    cin >> T;
    while (T--) {
        cin >> n;
        num.assign(4 * n + 1, -1);
        for (int i = 0; i < n * 2; ++i) {
            cin >> num[i << 1 | 1];
        }
        int ans = 0;
        multiset<int> st;
        for (int i = 0; i <= n; ++i) {
            st.insert(i);
            st.insert(i);
        }
        multiset<int> rst;
        for (int i = 1; i < 4 * n; ++i) {
            for (int j = 0; j < INT_MAX; ++j) {
                int l = i - j;
                int r = i + j;
                if (l < 1 || r >= 4 * n) {
                    break;
                }
                if (num[l] == -1 || num[r] == -1) {
                    continue;
                }
                if (num[l] != num[r]) {
                    break;
                }
                st.erase(num[l]);
                rst.insert(num[l]);
                rst.insert(num[l]);
                multiset<int>::iterator it = st.begin();
                ans = max(ans, *it);
            }
            for (int x : rst) {
                st.insert(x);
            }
            rst.clear();
        }
        cout << ans << endl;
    }

    return 0;
}
