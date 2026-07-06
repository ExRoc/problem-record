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

struct Node {
    int X, Y;

    Node() {}

    Node(int X, int Y) : X(X), Y(Y) {}

    bool operator<(const Node& other) const { return X < other.X; }
};

int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<Node> nodes(N);
    for (int i = 0; i < N; ++i) {
        cin >> nodes[i].X >> nodes[i].Y;
    }
    sort(nodes.begin(), nodes.end());
    FenwickTree<int> tree(N + 1);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        tree.Add(nodes[i].Y, 1);
        if (tree.Sum(0, nodes[i].Y) == 0) {
            ++ans;
        }
    }
    cout << ans << '\n';

    return 0;
}