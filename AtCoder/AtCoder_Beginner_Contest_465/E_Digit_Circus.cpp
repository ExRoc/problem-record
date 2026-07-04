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

    string N;
    cin >> N;
    int n = N.length();
    vector<vector<vector<vector<modint>>>> dp(
        n + 1, vector<vector<vector<modint>>>(
                   10, vector<vector<modint>>(1 << 10, vector<modint>(3, 0))));
    for (int num = 0; num < 10; ++num) {
        dp[1][num][1 << num][num % 3] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int num = 0; num < 10; ++num) {
            for (int preNum = 0; preNum < 10; ++preNum) {
                for (int status = 0; status < 1024; ++status) {
                    for (int mod = 0; mod < 3; ++mod) {
                        dp[i][num][status | (1 << num)][(mod + num) % 3] +=
                            dp[i - 1][preNum][status][mod];
                    }
                }
            }
        }
    }

    modint ans = 0;
    if (n == 1) {
        for (int num = 1; num <= N[0] - '0'; ++num) {
            if (num % 3 == 0 && num != 3) {
                ans += dp[1][num][1 << num][num % 3];
            }
        }
        cout << ans << '\n';
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        int numTop = 10;
        if (i == n) {
            numTop = N[0] - '0';
        }
        for (int num = 1; num < numTop; ++num) {
            for (int status = 0; status < 1024; ++status) {
                for (int mod = 0; mod < 3; ++mod) {
                    // onlyOne
                    if (mod == 0 && ((status >> 3) & 1) == 0 &&
                        __builtin_popcount(status) != 3) {
                        ans += dp[i][num][status][mod];
                    }
                    // onlyTwo
                    if (mod != 0 && ((status >> 3) & 1) == 1 &&
                        __builtin_popcount(status) != 3) {
                        ans += dp[i][num][status][mod];
                    }
                    // onlyThree
                    if (mod != 0 && ((status >> 3) & 1) == 0 &&
                        __builtin_popcount(status) == 3) {
                        ans += dp[i][num][status][mod];
                    }
                }
            }
        }
    }
    int preStatus = (1 << (N[0] - '0'));
    int preMod = (N[0] - '0') % 3;
    for (int i = n - 1; i >= 1; --i) {
        int numN = N[n - i] - '0';
        int numTop = numN;
        if (i == 1) {
            ++numTop;
        }
        for (int num = 0; num < numTop; ++num) {
            for (int status = 0; status < 1024; ++status) {
                for (int mod = 0; mod < 3; ++mod) {
                    int combineStatus = (preStatus | status);
                    int combineMod = (preMod + mod) % 3;
                    // onlyOne
                    if (combineMod == 0 && ((combineStatus >> 3) & 1) == 0 &&
                        __builtin_popcount(combineStatus) != 3) {
                        ans += dp[i][num][status][mod];
                    }
                    // onlyTwo
                    if (combineMod != 0 && ((combineStatus >> 3) & 1) != 0 &&
                        __builtin_popcount(combineStatus) != 3) {
                        ans += dp[i][num][status][mod];
                    }
                    // onlyThree
                    if (combineMod != 0 && ((combineStatus >> 3) & 1) == 0 &&
                        __builtin_popcount(combineStatus) == 3) {
                        ans += dp[i][num][status][mod];
                    }
                }
            }
        }
        preStatus |= (1 << numN);
        preMod = (preMod + numN) % 3;
    }
    cout << ans << '\n';

    return 0;
}