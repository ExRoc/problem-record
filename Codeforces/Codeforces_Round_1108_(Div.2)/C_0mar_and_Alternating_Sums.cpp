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
    int a, cnt;
    modint sum0, sum1;

    Node() {}

    Node(int a, int cnt, modint sum0, modint sum1)
        : a(a), cnt(cnt), sum0(sum0), sum1(sum1) {}

    bool operator<(const Node& other) const { return false; }
};

ostream& operator<<(ostream& out, const Node& node) {
    cout << "a = " << node.a << " cnt = " << node.cnt << " sum0 = " << node.sum0
         << " sum1 = " << node.sum1;
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int maxn = 200001;
    vector<modint> prod(maxn), invProd(maxn);
    prod[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        prod[i] = prod[i - 1] * i;
    }
    invProd[maxn - 1] = prod[maxn - 1].inv();
    for (int i = maxn - 2; i >= 0; --i) {
        invProd[i] = invProd[i + 1] * (i + 1);
    }
    auto C = [&](int n, int m) {
        return prod[n] * invProd[m] * invProd[n - m];
    };

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> cnt;
        for (int i = 1; i <= n; ++i) {
            long long a;
            cin >> a;
            ++cnt[a];
        }
        vector<Node> nodes;
        nodes.push_back(Node(0, 0, 1, 1));
        for (const auto& [key, value] : cnt) {
            modint sum0 = 0;
            modint sum1 = 0;
            for (int i = 0; i <= value; ++i) {
                if (i % 2 == 0) {
                    sum0 += C(value, i);
                } else {
                    sum1 += C(value, i);
                }
            }
            nodes.push_back(Node(key, value, sum0 * nodes.back().sum0,
                                 sum1 * nodes.back().sum1));
            // cout << nodes.back() << '\n';
        }
        modint ans = 0;
        if (nodes[1].a == -1) {
            for (int i = 2; i + 1 < (int)nodes.size(); ++i) {
                if (nodes[i].a + 1 != nodes[i + 1].a) {
                    continue;
                }
                ans += nodes[1].sum1 * (nodes[i + 1].sum1 / nodes[i - 1].sum1) *
                       (nodes[i - 1].sum0 / nodes[1].sum0) *
                       (nodes.back().sum0 / nodes[i + 1].sum0);
            }
        }
        cout << ans + nodes.back().sum0 << '\n';
    }

    return 0;
}