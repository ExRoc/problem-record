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

// 注意题目中的模数必须为 998244353
// 调用 multiply 方法时注意判断是否使用 move 代替深拷贝
class NTT {
   public:
    static vector<int> Multiply(vector<int> a, vector<int> b, int limit = -1) {
        if (a.empty() || b.empty()) {
            return {};
        }

        if (limit != -1) {
            if (static_cast<int>(a.size()) > limit) {
                a.resize(limit);
            }
            if (static_cast<int>(b.size()) > limit) {
                b.resize(limit);
            }
        }

        int need = static_cast<int>(a.size() + b.size() - 1);
        int n = 1;
        while (n < need) {
            n <<= 1;
        }

        a.resize(n);
        b.resize(n);

        Transform(a, false);
        Transform(b, false);

        for (int i = 0; i < n; ++i) {
            a[i] = static_cast<int>(static_cast<long long>(a[i]) * b[i] % kMod);
        }

        Transform(a, true);

        if (limit != -1 && static_cast<int>(a.size()) > limit) {
            a.resize(limit);
        } else {
            a.resize(need);
        }
        return a;
    }

   private:
    static constexpr int kMod = 998244353;
    static constexpr int kRoot = 3;

    static int ModPow(long long a, long long e) {
        long long res = 1;
        while (e > 0) {
            if (e & 1) {
                res = res * a % kMod;
            }
            a = a * a % kMod;
            e >>= 1;
        }
        return static_cast<int>(res);
    }

    static void Transform(vector<int>& a, bool invert) {
        int n = static_cast<int>(a.size());

        for (int i = 1, j = 0; i < n; ++i) {
            int bit = n >> 1;
            for (; (j & bit) != 0; bit >>= 1) {
                j ^= bit;
            }
            j ^= bit;
            if (i < j) {
                swap(a[i], a[j]);
            }
        }

        for (int len = 2; len <= n; len <<= 1) {
            int wlen = ModPow(kRoot, (kMod - 1) / len);
            if (invert) {
                wlen = ModPow(wlen, kMod - 2);
            }

            for (int i = 0; i < n; i += len) {
                long long w = 1;
                int half = len >> 1;
                for (int j = 0; j < half; ++j) {
                    int u = a[i + j];
                    int v = static_cast<int>(a[i + j + half] * w % kMod);
                    a[i + j] = (u + v) % kMod;
                    a[i + j + half] = (u - v + kMod) % kMod;
                    w = w * wlen % kMod;
                }
            }
        }

        if (invert) {
            int inv_n = ModPow(n, kMod - 2);
            for (int& x : a) {
                x = static_cast<int>(static_cast<long long>(x) * inv_n % kMod);
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    scanf("%d%d", &n, &m);
    int right = m * (n - 1);
    vector<int> ansTmp = {1};
    vector<int> res(m + 1, 1);
    --n;
    for (; n != 0; n >>= 1) {
        if ((n & 1) == 1) {
            ansTmp = NTT::Multiply(move(ansTmp), res);
        }
        res = NTT::Multiply(res, res);
    }
    modint ans = 0;
    for (int i = 0; i <= right; ++i) {
        int a;
        scanf("%d", &a);
        ans += modint(a) * ansTmp[i];
    }
    cout << ans << '\n';

    return 0;
}