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

modint C(int n, int m, const vector<modint>& prod,
         const vector<modint>& invprod) {
    if (n < m) {
        return 0;
    }
    return prod[n] * invprod[n - m] * invprod[m];
}

modint dfs(const vector<long long>& a, int l, int r, const vector<modint>& prod,
           const vector<modint>& invprod) {
    if (l > r) {
        return 1;
    }
    if (l == r) {
        if (a[l] == 1) {
            return 1;
        }
        return 0;
    }
    int ll = l - 1;
    int rr = r + 1;
    int d = -1;
    int mid = -1;
    while (ll < rr) {
        d = -d;
        int idx;
        if (d == 1) {
            ++ll;
            idx = ll;
        } else {
            --rr;
            idx = rr;
        }
        if (a[idx] == 1LL * (idx - l + 1) * (r - idx + 1)) {
            mid = idx;
            break;
        }
    }
    if (mid == -1) {
        return 0;
    }
    return dfs(a, l, mid - 1, prod, invprod) *
           dfs(a, mid + 1, r, prod, invprod) * C(r - l, mid - l, prod, invprod);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int maxn = 500000;
    vector<modint> prod(maxn + 1), invprod(maxn + 1);
    prod[0] = 1;
    for (int i = 1; i <= maxn; ++i) {
        prod[i] = prod[i - 1] * i;
    }
    invprod[maxn] = prod[maxn].inv();
    for (int i = maxn - 1; i >= 0; --i) {
        invprod[i] = invprod[i + 1] * (i + 1);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        cout << dfs(a, 1, n, prod, invprod) << '\n';
    }

    return 0;
}