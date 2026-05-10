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

int main() {
    ios::sync_with_stdio(false);

    long long x, y;
    cin >> x >> y;
    vector<long long> px;
    for (int i = 1; i <= x / i; ++i) {
        if (x % i == 0) {
            px.push_back(i);
            if (x / i != i) {
                px.push_back(x / i);
            }
        }
    }
    vector<long long> py;
    for (int i = 1; i <= y / i; ++i) {
        if (y % i == 0) {
            py.push_back(i);
            if (y / i != i) {
                py.push_back(y / i);
            }
        }
    }
    set<long long> st;
    for (long long a : px) {
        for (long long b : py) {
            st.insert(a * b);
        }
    }
    modint ans = 0;
    for (auto x : st) {
        ans += modint(x).pow(x);
    }
    cout << ans << '\n';

    return 0;
}