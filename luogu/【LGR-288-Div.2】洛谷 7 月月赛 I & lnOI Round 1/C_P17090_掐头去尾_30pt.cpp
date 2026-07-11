#include <bits/stdc++.h>
using namespace std;

class Log2Table {
   public:
    static int Get(int n) {
        static vector<int> table = {0, 0};
        if (n >= static_cast<int>(table.size())) {
            int old = table.size();
            table.resize(n + 1);
            for (int i = max(2, old); i <= n; ++i) {
                table[i] = table[i / 2] + 1;
            }
        }
        return table[n];
    }
};

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
    int fromIdx, toIdx, front, back, len;

    Node() {}

    Node(int fromIdx, int toIdx, int front, int back, int len)
        : fromIdx(fromIdx), toIdx(toIdx), front(front), back(back), len(len) {}

    bool operator<(const Node& other) const { return false; }
};

ostream& operator<<(ostream& out, const Node& node) {
    out << "fromIdx: " << node.fromIdx << " toIdx: " << node.toIdx
        << " front: " << node.front << " back: " << node.back
        << " len: " << node.len;
    return out;
}

Node push(const Node& node, int idx, int x) {
    if (node.len == 1) {
        if (x > node.front) {
            return Node(node.fromIdx, idx + 1, x, x, 1);
        }
        return Node(node.fromIdx, idx + 1, node.front, x, 2);
    }
    if (x > node.front) {
        return Node(node.fromIdx, idx + 1, x, node.back, node.len);
    }
    if (x > node.back) {
        return Node(node.fromIdx, idx + 1, node.front, x, node.len);
    }
    return Node(node.fromIdx, idx + 1, node.front, x, node.len + 1);
}

Node merge(const Node& node1, const Node& node2, const vector<int>& a) {
    if (node1.len == 0) {
        return node2;
    }
    if (node2.toIdx - node2.fromIdx == 1) {
        return push(node1, node2.fromIdx, node2.front);
    }
    if (node2.len == 1) {
        return push(node1, node2.toIdx - 1, node2.front);
    }
    Node node = push(push(node1, node2.fromIdx, a[node2.fromIdx]),
                     node2.fromIdx + 1, a[node2.fromIdx + 1]);
    node.fromIdx = node1.fromIdx;
    node.toIdx = node2.toIdx;
    node.front = node2.front;
    node.back = node2.back;
    node.len += node2.len;
    if (a[node2.fromIdx] >= a[node2.fromIdx + 1]) {
        node.len -= 2;
    } else {
        node.len -= 1;
    }
    return node;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    FenwickTree<int> sum(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] > a[i - 1]) {
            sum.Add(i, 1);
        }
    }
    vector<vector<Node>> st(n + 1, vector<Node>(Log2Table::Get(n) + 1));
    stack<int> nextMaxIdx;
    nextMaxIdx.push(n);
    st[n][0] = Node(n, n + 1, a[n], a[n], 1);
    cout << "st[" << n << "][" << 0 << "] = " << st[n][0] << '\n';
    for (int i = n - 1; i >= 1; --i) {
        while (!nextMaxIdx.empty() && a[nextMaxIdx.top()] <= a[i]) {
            nextMaxIdx.pop();
        }
        int nextIdx;
        if (nextMaxIdx.empty()) {
            nextIdx = n + 1;
        } else {
            nextIdx = nextMaxIdx.top();
        }
        st[i][0] = Node(i, nextIdx, a[i], a[nextIdx - 1],
                        nextIdx - i - sum.Sum(i + 1, nextIdx));
        cout << "st[" << i << "][" << 0 << "] = " << st[i][0] << '\n';
        nextMaxIdx.push(i);
    }
    for (int j = 1; j <= Log2Table::Get(n); ++j) {
        for (int i = 1; i <= n; ++i) {
            if (st[i][j - 1].toIdx > n) {
                st[i][j] = st[i][j - 1];
                cout << "st[" << i << "][" << j << "] = " << st[i][j] << '\n';
                continue;
            }
            st[i][j] = merge(st[i][j - 1], st[st[i][j - 1].toIdx][j - 1], a);
            cout << "st[" << i << "][" << j << "] = " << st[i][j] << '\n';
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int idx = l;
        Node node = Node(l, l, 0, 0, 0);
        bool flag = false;
        for (int j = Log2Table::Get(n); j >= 0; --j) {
            if (st[idx][j].toIdx > r + 1) {
                continue;
            }
            if (!flag) {
                node = st[idx][j];
                flag = true;
            } else {
                node = merge(node, st[idx][j], a);
            }
            cout << "midNode: " << node << '\n';
            idx = st[idx][j].toIdx;
            if (idx > n) {
                break;
            }
        }
        cout << "idx = " << idx << '\n';
        cout << "node: " << node << '\n';
        if (idx != r + 1) {
            Node left = Node(idx, r + 1, a[idx], a[r],
                             r - idx + 1 - sum.Sum(idx + 1, r + 1));
            node = merge(node, left, a);
        }
        cout << node.len << '\n';
    }

    return 0;
}