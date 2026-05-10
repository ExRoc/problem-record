#include <bits/stdc++.h>
using namespace std;

const int maxcnt = 2000000 + 100;
const int Size = 2;

struct Trie {
    int root, cnt;
    int tree[maxcnt][Size];
    int val[maxcnt];

    int create() {
        ++cnt;
        memset(tree[cnt], 0, sizeof(tree[cnt]));
        val[cnt] = 0;
        return cnt;
    }

    void Init() {
        cnt = 0;
        root = create();
    }

    inline int id(char ch) { return ch - '0'; }

    void add(const string& s) {
        int pos = root;
        for (int i = 0; i < (int)s.length(); ++i) {
            int w = id(s[i]);
            if (tree[pos][w] == 0) {
                tree[pos][w] = create();
            }
            pos = tree[pos][w];
            ++val[pos];
        }
    }

    string query(int m) {
        int fa = root;
        int pos = root;
        string ans;
        for (int i = 0; i < m; ++i) {
            int pos0 = tree[pos][0];
            int pos1 = tree[pos][1];
            if (pos0 == 0 && pos1 == 0) {
                break;
            }
            if (pos0 == 0) {
                ans += '1';
                fa = pos;
                pos = pos1;
                break;
            }
            if (pos1 == 0) {
                ans += '0';
                fa = pos;
                pos = pos0;
                continue;
            }
            if (i == m - 1) {
                return "";
            }
            if (val[pos0] > val[pos1]) {
                ans += '0';
                fa = pos;
                pos = pos1;
            } else {
                ans += '1';
                fa = pos;
                pos = pos0;
            }
        }
        while (ans.length() < m) {
            ans += '0';
        }
        return ans;
    }
} tree;

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    tree.Init();
    string s;
    set<string> st;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (st.find(s) == st.end()) {
            st.insert(s);
            tree.add(s);
        }
    }
    string ans = tree.query(m);
    if (ans == "") {
        cout << "No" << '\n';
    } else {
        cout << "Yes" << '\n' << ans << '\n';
    }

    return 0;
}