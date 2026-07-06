#include <bits/stdc++.h>
using namespace std;

struct Query {
    int idx, l, r, blockId;
    static int blockSize;

    Query() {}

    Query(int idx, int l, int r)
        : idx(idx), l(l), r(r), blockId(l / blockSize) {}

    bool operator<(const Query& other) const {
        return blockId == other.blockId ? r < other.r : blockId < other.blockId;
    }
};

int Query::blockSize;

void add(vector<int>& cnt, int x, int b, int& ans) {
    ++cnt[x];
    if (cnt[x] >= b) {
        ++ans;
    }
}

void del(vector<int>& cnt, int x, int b, int& ans) {
    if (cnt[x] >= b) {
        --ans;
    }
    --cnt[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, n, q;
    cin >> a >> b >> n >> q;
    vector<int> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    Query::blockSize = sqrt(n);
    vector<Query> querys;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        querys.push_back(Query(i, l, r));
    }
    sort(querys.begin(), querys.end());
    int l = 1;
    int r = 0;
    int ansTmp = 0;
    vector<int> cnt(a + 1, 0);
    vector<int> ans(q);
    for (const Query& query : querys) {
        while (r < query.r) {
            ++r;
            add(cnt, s[r], b, ansTmp);
        }
        while (l > query.l) {
            --l;
            add(cnt, s[l], b, ansTmp);
        }
        while (r > query.r) {
            del(cnt, s[r], b, ansTmp);
            --r;
        }
        while (l < query.l) {
            del(cnt, s[l], b, ansTmp);
            ++l;
        }
        ans[query.idx] = ansTmp;
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}