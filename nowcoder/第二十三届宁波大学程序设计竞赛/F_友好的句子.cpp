#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        set<string> vs;
        for (int i = 0; i < n; ++i) {
            string v;
            cin >> v;
            vs.insert(v);
        }
        string s;
        while (getline(cin, s), s.length() == 0) {
        }
        istringstream sin(s);
        string w;
        set<string> ws;
        while (sin >> w) {
            ws.insert(w);
        }
        bool flag = true;
        for (const string& v : vs) {
            if (ws.find(v) != ws.end() && ws.find(v + "ed") != ws.end()) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            cout << "not friendly" << '\n';
        } else {
            cout << "friendly" << '\n';
        }
    }

    return 0;
}