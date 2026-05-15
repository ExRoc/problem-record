#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int a;
            cin >> a;
            A[i].push_back(a);
        }
    }
    set<int> st, stIdx;
    while (q--) {
        int p;
        cin >> p;
        if (stIdx.find(p) != stIdx.end()) {
            cout << st.size() << '\n';
            continue;
        }
        stIdx.insert(p);
        for (int x : A[p]) {
            st.insert(x);
        }
        cout << st.size() << '\n';
    }

    return 0;
}