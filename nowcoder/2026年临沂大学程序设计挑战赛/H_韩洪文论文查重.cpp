#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int cnt_;
    vector<int> parent_;

    explicit DSU(int n) : cnt_(n), parent_(n + 1) {
        for (int i = 0; i <= n; ++i) {
            parent_[i] = i;
        }
    }

    int Find(int x) {
        return parent_[x] == x ? x : parent_[x] = Find(parent_[x]);
    }

    void Unite(int x, int y) {
        x = Find(x);
        y = Find(y);
        if (x != y) {
            --cnt_;
            parent_[y] = x;
        }
    }

    bool Same(int x, int y) { return Find(x) == Find(y); }
};

int main() {
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;
    int lenS = s.length();
    int lenT = t.length();
    s = '#' + s + '#';
    DSU toL(lenS + 2), toR(lenS + 2);
    int idx = 1;
    while (idx + lenT - 1 <= lenS) {
        int idxTmp = toR.Find(idx);
        bool match = true;
        for (int i = 0; i < lenT; ++i) {
            if (idxTmp > lenS || s[idxTmp] != t[i]) {
                match = false;
                break;
            }
            idxTmp = toR.Find(idxTmp + 1);
        }
        if (!match) {
            idx = toR.Find(idx + 1);
            continue;
        }
        idxTmp = toR.Find(idx);
        for (int i = 0; i < lenT; ++i) {
            toR.Unite(idxTmp + 1, idxTmp);
            toL.Unite(idxTmp - 1, idxTmp);
            idxTmp = toR.Find(idxTmp);
        }
        idxTmp = toL.Find(idx);
        for (int i = 0; i < lenT; ++i) {
            if (idxTmp == 0) {
                break;
            }
            idxTmp = toL.Find(idxTmp - 1);
        }
        idx = idxTmp;
    }
    idx = toR.Find(1);
    while (idx <= lenS) {
        cout << s[idx];
        idx = toR.Find(idx + 1);
    }
    cout << '\n';

    return 0;
}
