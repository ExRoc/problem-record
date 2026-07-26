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
    cin.tie(nullptr);

    int Log = Log2Table::Get(1000000) + 1;
    int T;
    cin >> T;
    while (T--) {
        int N, Q;
        cin >> N >> Q;
        vector<int> A(N + 1, 0);
        vector<vector<int>> sum(Log + 1, vector<int>(N + 1, 0));
        for (int i = 1; i <= N; ++i) {
            cin >> A[i];
            A[i] ^= A[i - 1];
            for (int j = 0; j <= Log; ++j) {
                sum[j][i] = sum[j][i - 1] + ((A[i] >> j) & 1);
            }
        }
        while (Q--) {
            int L, R;
            cin >> L >> R;
            modint ans = 0;
            for (int i = 0; i <= Log; ++i) {
                modint cnt1 = sum[i][R] - sum[i][L - 1];
                modint cnt0 = (R - L + 1) - cnt1;
                if (((A[L - 1] >> i) & 1) == 0) {
                    ++cnt0;
                } else {
                    ++cnt1;
                }
                ans += cnt0 * cnt1 * modint(2).pow(i);
            }
            cout << ans << '\n';
        }
    }

    return 0;
}