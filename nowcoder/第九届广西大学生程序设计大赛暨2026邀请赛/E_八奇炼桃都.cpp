#include <bits/stdc++.h>
using namespace std;

class NTT {
   private:
    static constexpr int MOD = 998244353;
    static constexpr int ROOT = 3;

    static int mod_pow(long long a, long long e) {
        long long res = 1;
        while (e > 0) {
            if (e & 1) {
                res = res * a % MOD;
            }
            a = a * a % MOD;
            e >>= 1;
        }
        return static_cast<int>(res);
    }

    static void transform(vector<int>& a, bool invert) {
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
            int wlen = mod_pow(ROOT, (MOD - 1) / len);
            if (invert) {
                wlen = mod_pow(wlen, MOD - 2);
            }

            for (int i = 0; i < n; i += len) {
                long long w = 1;
                int half = len >> 1;
                for (int j = 0; j < half; ++j) {
                    int u = a[i + j];
                    int v = static_cast<int>(a[i + j + half] * w % MOD);
                    a[i + j] = (u + v) % MOD;
                    a[i + j + half] = (u - v + MOD) % MOD;
                    w = w * wlen % MOD;
                }
            }
        }

        if (invert) {
            int inv_n = mod_pow(n, MOD - 2);
            for (int& x : a) {
                x = static_cast<int>(static_cast<long long>(x) * inv_n % MOD);
            }
        }
    }

   public:
    static vector<int> multiply(vector<int> a, vector<int> b, int limit = -1) {
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

        transform(a, false);
        transform(b, false);

        for (int i = 0; i < n; ++i) {
            a[i] = static_cast<int>(static_cast<long long>(a[i]) * b[i] % MOD);
        }

        transform(a, true);

        if (limit != -1 && static_cast<int>(a.size()) > limit) {
            a.resize(limit);
        } else {
            a.resize(need);
        }
        return a;
    }
};

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

    const int maxn = 200001;
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), cntA(maxn, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ++cntA[a[i]];
        }
        vector<int> b(n), cntB(maxn, 0);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            ++cntB[b[i]];
        }
        vector<int> multA = NTT::multiply(cntA, cntA);
        vector<int> multB = NTT::multiply(cntB, cntB);
        for (int i = 0; i < n; ++i) {
            --multA[a[i] * 2];
            --multB[b[i] * 2];
        }
        int cnt = 0;
        for (int i = 0; i < maxn; ++i) {
            if (cntA[i] != 0 && cntB[i] != 0) {
                ++cnt;
            }
        }
        modint ans = 0;
        int top = min(multA.size(), multB.size());
        for (int i = 0; i < top; ++i) {
            ans += modint(multA[i]) * multB[i];
        }
        cout << ans - modint(cnt) * (cnt - 1) * 2 << '\n';
    }

    return 0;
}