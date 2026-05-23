#include <bits/stdc++.h>
using namespace std;

template <class T>
struct FenwickTree {
   public:
    FenwickTree() : n_(0) {}
    explicit FenwickTree(int n) : n_(n), data_(n) {}

    void Add(int p, T x) {
        assert(0 <= p && p < n_);
        ++p;
        while (p <= n_) {
            data_[p - 1] += x;
            p += p & -p;
        }
    }

    T Sum(int l, int r) {
        assert(0 <= l && l <= r && r <= n_);
        return Sum(r) - Sum(l);
    }

   private:
    int n_;
    vector<T> data_;

    T Sum(int r) {
        T s = 0;
        while (r > 0) {
            s += data_[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;
    map<int, int> cnts;
    cnts[0] = N;
    const int maxn = 600000 + 100;
    FenwickTree<int> tree(maxn);
    tree.Add(0, N);
    vector<int> nums(N + 1, 0);
    while (Q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int x;
            cin >> x;
            tree.Add(nums[x], -1);
            --cnts[nums[x]];
            if (cnts[nums[x]] == 0) {
                cnts.erase(nums[x]);
            }
            ++nums[x];
            ++cnts[nums[x]];
            tree.Add(nums[x], 1);
        } else {
            int y;
            cin >> y;
            y += cnts.begin()->first;
            cout << tree.Sum(y, maxn) << '\n';
        }
    }

    return 0;
}