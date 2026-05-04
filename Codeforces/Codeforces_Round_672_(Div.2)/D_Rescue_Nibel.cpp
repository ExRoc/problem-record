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

typedef ModInt<998244353> mint;

struct Node {
    int pos, mark;

    Node() {}

    Node(int pos, int mark) : pos(pos), mark(mark) {}

    bool operator<(const Node& other) const {
        return pos == other.pos ? mark < other.mark : pos < other.pos;
    }
};

mint C(int n, int k, vector<mint>& prod) {
    return prod[n] / prod[n - k] / prod[k];
}

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<Node> nodes;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        nodes.push_back(Node(l, 1));
        nodes.push_back(Node(r + 1, -1));
    }
    sort(nodes.begin(), nodes.end());
    int cnt = 0;
    mint ans = 0;
    vector<mint> prod(n + 1);
    prod[0] = 1;
    for (int i = 1; i <= n; ++i) {
        prod[i] = prod[i - 1] * i;
    }
    for (Node& node : nodes) {
        if (node.mark == 1) {
            ++cnt;
            if (cnt >= k) {
                ans += C(cnt - 1, k - 1, prod);
            }
        } else {
            --cnt;
        }
    }
    cout << ans << '\n';

    return 0;
}