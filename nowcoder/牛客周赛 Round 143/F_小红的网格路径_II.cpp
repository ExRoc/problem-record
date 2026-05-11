#include <bits/stdc++.h>
using namespace std;

template <int MOD>
class ModInt {
   public:
    constexpr ModInt(long long v = 0) : val_(v % MOD) {
        if (val_ < 0) {
            val_ += MOD;
        }
    }

    constexpr int value() const { return val_; }

    static constexpr int mod() { return MOD; }

    constexpr ModInt pow(long long n) const {
        ModInt res = 1;
        ModInt a = *this;
        if (n < 0) {
            a = a.inv();
            n = -n;
        }
        while (n) {
            if (n & 1) {
                res *= a;
            }
            a *= a;
            n >>= 1;
        }
        return res;
    }

    constexpr ModInt inv() const { return pow(MOD - 2); }

    constexpr ModInt operator-() const { return ModInt(-val_); }

    constexpr ModInt& operator+=(const ModInt& rhs) {
        val_ += rhs.val_;
        if (val_ >= MOD) {
            val_ -= MOD;
        }
        return *this;
    }

    constexpr ModInt& operator-=(const ModInt& rhs) {
        val_ -= rhs.val_;
        if (val_ < 0) {
            val_ += MOD;
        }
        return *this;
    }

    constexpr ModInt& operator*=(const ModInt& rhs) {
        val_ = static_cast<long long>(val_) * rhs.val_ % MOD;
        return *this;
    }

    constexpr ModInt& operator/=(const ModInt& rhs) {
        return *this *= rhs.inv();
    }

    constexpr ModInt& operator++() { return *this += 1; }

    constexpr ModInt operator++(int) {
        ModInt old = *this;
        ++(*this);
        return old;
    }

    constexpr ModInt& operator--() { return *this -= 1; }

    constexpr ModInt operator--(int) {
        ModInt old = *this;
        --(*this);
        return old;
    }

    friend constexpr ModInt operator+(ModInt a, const ModInt& b) {
        return a += b;
    }

    friend constexpr ModInt operator-(ModInt a, const ModInt& b) {
        return a -= b;
    }

    friend constexpr ModInt operator*(ModInt a, const ModInt& b) {
        return a *= b;
    }

    friend constexpr ModInt operator/(ModInt a, const ModInt& b) {
        return a /= b;
    }

    friend constexpr bool operator==(const ModInt& a, const ModInt& b) {
        return a.val_ == b.val_;
    }

    friend constexpr bool operator!=(const ModInt& a, const ModInt& b) {
        return a.val_ != b.val_;
    }

    friend constexpr ModInt operator+(long long x, const ModInt& m) {
        return ModInt(x) + m;
    }

    friend constexpr ModInt operator-(long long x, const ModInt& m) {
        return ModInt(x) - m;
    }

    friend constexpr ModInt operator*(long long x, const ModInt& m) {
        return ModInt(x) * m;
    }

    friend constexpr ModInt operator/(long long x, const ModInt& m) {
        return ModInt(x) / m;
    }

    friend std::ostream& operator<<(std::ostream& os, const ModInt& m) {
        return os << m.val_;
    }

    friend std::istream& operator>>(std::istream& is, ModInt& m) {
        long long x;
        is >> x;
        m = ModInt(x);
        return is;
    }

   private:
    int val_;
};

typedef ModInt<1000000007> modint;

struct Node {
    int x, y;

    Node() {}

    Node(int x, int y) : x(x), y(y) {}

    bool operator<(const Node& other) const { return y < other.y; }
};

int intersectlen(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) {
        swap(a, b);
    }
    return max(min(a.second, b.second) - b.first + 1, 0);
}

int main() {
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    vector<Node> nodes(k);
    for (int i = 0; i < k; ++i) {
        cin >> nodes[i].x >> nodes[i].y;
    }
    sort(nodes.begin(), nodes.end());
    map<pair<int, int>, modint> dp;
    int idx = 0;
    dp[{1, 1}] = 1;
    for (Node& node : nodes) {
        if (idx != node.y - 1) {
            modint tmp = 0;
            for (auto [lr, v] : dp) {
                tmp += v * (lr.second - lr.first + 1);
            }
            tmp *= modint(n).pow(node.y - idx - 2);
            dp.clear();
            dp[{1, n}] = tmp;
        }
        map<pair<int, int>, modint> dpTmp;
        if (node.x != 1) {
            pair<int, int> p(1, node.x - 1);
            for (auto [lr, v] : dp) {
                dpTmp[p] += v * intersectlen(p, lr);
            }
        }
        if (node.x != n) {
            pair<int, int> p(node.x + 1, n);
            for (auto [lr, v] : dp) {
                dpTmp[p] += v * intersectlen(p, lr);
            }
        }
        idx = node.y;
        swap(dp, dpTmp);
    }
    if (k > 0 && nodes.back().y != m) {
        modint tmp = 0;
        for (auto [lr, v] : dp) {
            tmp += v * (lr.second - lr.first + 1);
        }
        tmp *= modint(n).pow(m - idx - 1);
        dp.clear();
        dp[{1, n}] = tmp;
    }
    for (auto [lr, v] : dp) {
        if (lr.first <= n && lr.second >= n) {
            cout << v << '\n';
        }
    }

    return 0;
}