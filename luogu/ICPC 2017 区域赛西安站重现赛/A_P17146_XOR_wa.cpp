#include <bits/stdc++.h>
using namespace std;

struct Query {
    int L, R, idx;

    Query() {}

    Query(int _L, int _R, int _idx) : L(_L), R(_R), idx(_idx) {}

    bool operator<(const Query& other) const { return false; }
};

struct Base {
    int base, pos;

    Base() {}

    Base(int _base, int _pos) : base(_base), pos(_pos) {}

    bool operator<(const Base& other) const { return false; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, Q, K;
        cin >> N >> Q >> K;
        vector<int> A(N + 1);
        for (int i = 1; i <= N; ++i) {
            cin >> A[i];
        }
        vector<vector<Query>> querys(N + 1);
        for (int i = 0; i < Q; ++i) {
            int L, R;
            cin >> L >> R;
            querys[R].push_back(Query(L, R, i));
        }
        vector<Base> bases(28, Base(0, 0));
        vector<int> ans(Q);
        for (int i = 1; i <= N; ++i) {
            Base base(A[i], i);
            for (int j = 27; j >= 0; --j) {
                if (((base.base >> j) & 1) == 0 || ((K >> j) & 1) == 1) {
                    continue;
                }
                if (base.pos < bases[j].pos) {
                    base.base ^= bases[j].base;
                    continue;
                }
                swap(bases[j], base);
                base.base ^= bases[j].base;
            }
            for (const Query& query : querys[i]) {
                ans[query.idx] = 0;
                for (int j = 27; j >= 0; --j) {
                    if (bases[j].pos >= query.L &&
                        (ans[query.idx] ^ bases[j].base) > ans[query.idx] &&
                        ((K >> j) & 1) == 0) {
                        ans[query.idx] ^= bases[j].base;
                    }
                }
                ans[query.idx] |= K;
            }
        }
        for (int i = 0; i < Q; ++i) {
            cout << ans[i] << '\n';
        }
    }

    return 0;
}