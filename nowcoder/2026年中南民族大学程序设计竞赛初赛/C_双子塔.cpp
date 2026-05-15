#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    set<int> st;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        st.insert(i);
    }
    long long sum = 0;
    while (q--) {
        string cmd;
        cin >> cmd;
        if (cmd == "BORROW") {
            int x;
            cin >> x;
            if (st.find(x) == st.end()) {
                cout << "ERROR" << '\n';
            } else {
                st.erase(x);
                sum += a[x];
            }
        } else if (cmd == "RETURN") {
            int x;
            cin >> x;
            if (st.find(x) == st.end()) {
                sum -= a[x];
                st.insert(x);
            } else {
                cout << "ERROR" << '\n';
            }
        } else if (cmd == "CHECK") {
            cout << st.size() << '\n';
        } else {
            cout << sum << '\n';
        }
    }

    return 0;
}