#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if ((n & (-n)) != n) {
        cout << "NO" << '\n';
        return 0;
    }
    vector<int> g(n);
    set<int> gst;
    bool containsZero = false;
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
        if (g[i] == 0) {
            containsZero = true;
        }
        gst.insert(g[i]);
    }
    if (!containsZero) {
        cout << "NO" << '\n';
        return 0;
    }
    set<int> st;
    st.insert(0);
    for (int i = 0; i < n; ++i) {
        if (st.find(g[i]) != st.end()) {
            continue;
        }
        vector<int> stTmp;
        for (int x : st) {
            if (gst.find(g[i] ^ x) == gst.end()) {
                cout << "NO" << '\n';
                return 0;
            }
            stTmp.push_back(g[i] ^ x);
        }
        for (int x : stTmp) {
            st.insert(x);
        }
    }
    cout << "YES" << '\n';

    return 0;
}