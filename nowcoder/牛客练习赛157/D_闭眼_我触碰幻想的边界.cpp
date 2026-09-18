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
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> pre(n + 2, 0), pre2(n + 2, 0);
    int pre2Tmp = 0;
    for (int i = 1; i <= n + 1; ++i) {
        if (a[i] != a[i - 1]) {
            pre[i] = i - 1;
        } else {
            pre[i] = pre[i - 1];
        }
        if (a[i] == 0) {
            continue;
        }
        if (a[i] != a[pre2Tmp]) {
            pre2[i] = pre2Tmp;
        } else {
            pre2[i] = pre2[pre2Tmp];
        }
        pre2Tmp = i;
    }
    vector<modint> dp(n + 2, 0);
    vector<modint> dpSum(n + 2, 0);
    dp[0] = 1;
    dpSum[0] = 1;
    for (int i = 1; i <= n + 1; ++i) {
        if (a[i] == 0) {
            if (pre[i] == 0) {
                dp[i] = dpSum[i - 1];
            } else {
                if (a[pre[pre[i]]] != 0) {
                    cout << 0 << '\n';
                    return 0;
                }
                dp[i] = dpSum[i - 1] - dpSum[pre[i]];
                if (i - a[pre[i]] - 1 >= 0 && a[i - a[pre[i]] - 1] == 0 &&
                    i - a[pre[i]] - 1 < pre[i]) {
                    if (pre2[pre[i]] == 0 || i - a[pre[i]] - 1 > pre2[pre[i]]) {
                        dp[i] += dp[i - a[pre[i]] - 1];
                    }
                }
            }
        }
        dpSum[i] = dpSum[i - 1] + dp[i];
    }
    cout << dp[n + 1] << '\n';

    return 0;
}