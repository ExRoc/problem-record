#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    set<char> st(s.begin(), s.end());
    cout << ((int)st.size() == 2 ? "Yes" : "No") << '\n';

    return 0;
}