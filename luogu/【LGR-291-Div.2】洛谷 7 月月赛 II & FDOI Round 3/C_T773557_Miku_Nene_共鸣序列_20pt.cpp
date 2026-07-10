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

typedef ModInt<998244353> modint;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        modint a, b, p, q;
        long long n;
        cin >> a >> b >> p >> q >> n;
        vector<modint> f(n + 1);
        vector<modint> sum(n + 1);
        f[0] = a;
        sum[0] = a;
        f[1] = b;
        sum[1] = a + b;
        for (int i = 2; i <= n; ++i) {
            f[i] = p * f[i - 1] + q * f[i - 2];
            sum[i] = sum[i - 1] + f[i];
        }
        modint ans = 0;
        for (int i = 0; i <= n; ++i) {
            ans += f[i] * sum[n - i];
        }
        cout << ans * p * q << '\n';
    }

    return 0;
}