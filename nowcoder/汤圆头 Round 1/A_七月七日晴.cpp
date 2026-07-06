#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    set<char> st(s.begin(), s.end());
    cout << (st.size() == 7 ? "YES" : "NO") << '\n';

    return 0;
}