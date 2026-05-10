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

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<map<int, int>> G(n + 1, map<int, int>());
        for (int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            ++G[u][v];
        }
        vector<int> degin(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (auto [pos, cnt] : G[i]) {
                ++degin[pos];
            }
        }
        queue<int> que;
        for (int i = 1; i <= n; ++i) {
            if (degin[i] == 0) {
                que.push(i);
            }
        }
        vector<int> topsort;
        while (!que.empty()) {
            int tmp = que.front();
            que.pop();
            topsort.push_back(tmp);
            for (auto [pos, cnt] : G[tmp]) {
                --degin[pos];
                if (degin[pos] == 0) {
                    que.push(pos);
                }
            }
        }
        if (topsort.size() != n) {
            cout << 0 << '\n';
            continue;
        }
        modint ans = 1;
        for (int i = 0; i < n - 1; ++i) {
            int u = topsort[i];
            int v = topsort[i + 1];
            auto it = G[u].find(v);
            if (it == G[u].end()) {
                ans = 0;
                break;
            }
            ans *= it->second;
        }
        cout << ans << '\n';
    }

    return 0;
}