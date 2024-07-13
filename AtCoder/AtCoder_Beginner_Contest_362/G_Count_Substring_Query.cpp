#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 500000 + 100;
const int maxcnt = 500000 + 100;
const int ac_size = 26;

struct ac_auto {
    int cnt, root, head, tail;
    int tree[maxcnt][ac_size];
    int fail[maxcnt], que[maxcnt];
    vector<int> vct[maxcnt];
    int tot[maxcnt], ans[maxn];

    int create() {
        memset(tree[cnt], -1, sizeof(tree[cnt]));
        ++cnt;
        return cnt - 1;
    }

    void Init() {
        cnt = 0;
        root = create();
    }

    int id(char ch) { return ch - 'a'; }

    void insert(char* str, int idx) {
        int pos = root;
        for (int i = 0; str[i]; ++i) {
            int w = id(str[i]);
            if (tree[pos][w] == -1) {
                tree[pos][w] = create();
            }
            pos = tree[pos][w];
        }
        vct[pos].push_back(idx);
    }

    void build() {
        fail[root] = root;
        que[0] = root;
        head = tail = 1;
        for (int i = 0; i < ac_size; ++i) {
            if (tree[root][i] == -1) {
                tree[root][i] = root;
            } else {
                fail[tree[root][i]] = root;
                que[tail++] = tree[root][i];
            }
        }
        while (head != tail) {
            int pos = que[head++];
            for (int i = 0; i < ac_size; ++i) {
                if (tree[pos][i] == -1) {
                    tree[pos][i] = tree[fail[pos]][i];
                } else {
                    fail[tree[pos][i]] = tree[fail[pos]][i];
                    que[tail++] = tree[pos][i];
                }
            }
        }
    }

    void query(char* str) {
        int pos = root;
        for (int i = 0; str[i]; ++i) {
            int w = id(str[i]);
            pos = tree[pos][w];
            ++tot[pos];
        }
        for (int i = cnt - 1; i >= 0; --i) {
            tot[fail[que[i]]] += tot[que[i]];
            for (int idx : vct[que[i]]) {
                ans[idx] = tot[que[i]];
            }
        }
    }
};

int q;
ac_auto ac;
char s[maxn], t[maxn];

int main() {
    ios::sync_with_stdio(false);

    cin >> s;
    cin >> q;
    ac.Init();
    for (int i = 0; i < q; ++i) {
        cin >> t;
        ac.insert(t, i);
    }
    ac.build();
    ac.query(s);
    for (int i = 0; i < q; ++i) {
        cout << ac.ans[i] << endl;
    }

    return 0;
}
