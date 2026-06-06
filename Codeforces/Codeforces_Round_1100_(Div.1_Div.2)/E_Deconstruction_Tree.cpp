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

void dfs1(int root, int fa, const vector<vector<int>>& G,
          vector<int>& maxSubTree) {
    for (int pos : G[root]) {
        if (pos == fa) {
            continue;
        }
        dfs1(pos, root, G, maxSubTree);
        maxSubTree[root] = max({maxSubTree[root], pos, maxSubTree[pos]});
    }
}

void dfs2(int root, int fa, const vector<vector<int>>& G,
          set<int, greater<int>>& st, vector<int>& tmp) {
    st.erase(root);
    tmp.push_back(root);
    for (int pos : G[root]) {
        if (pos == fa) {
            continue;
        }
        dfs2(pos, root, G, st, tmp);
    }
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> G(n + 1);
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int maxLeaf = 1;
        for (int i = 1; i <= n; ++i) {
            if ((int)G[i].size() == 1) {
                maxLeaf = i;
            }
        }
        if (maxLeaf == n) {
            cout << 1 << '\n';
            continue;
        }
        vector<modint> dp(n + 1);
        dp[maxLeaf] = 1;
        vector<int> maxSubTree(n + 1);
        dfs1(n, n, G, maxSubTree);
        vector<modint> dpSum(n + 1);
        dpSum[maxLeaf] = 1;
        for (int i = maxLeaf + 1; i < n; ++i) {
            if (maxSubTree[i] < i) {
                dp[i] = dpSum[i - 1] - dpSum[maxSubTree[i]];
            }
            dpSum[i] = dpSum[i - 1] + dp[i];
        }
        set<int, greater<int>> st;
        for (int i = 1; i < n; ++i) {
            st.insert(i);
        }
        modint ans = 0;
        for (int pos : G[n]) {
            vector<int> tmp;
            dfs2(pos, n, G, st, tmp);
            for (int pos : tmp) {
                if (pos > *(st.begin())) {
                    ans += dp[pos];
                }
            }
            for (int pos : tmp) {
                st.insert(pos);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}