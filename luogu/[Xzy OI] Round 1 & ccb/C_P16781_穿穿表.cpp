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

typedef ModInt<1145141> modint;

modint getC(int n, int m, const vector<modint>& pro,
            const vector<modint>& invpro) {
    if (n < m) {
        return 0;
    }
    return pro[n] * invpro[m] * invpro[n - m];
}

modint Lucas(int n, int m, int MOD, const vector<modint>& pro,
             const vector<modint>& invpro) {
    if (n < MOD && m < MOD) {
        return getC(n, m, pro, invpro);
    }
    modint tmp = getC(n % MOD, m % MOD, pro, invpro);
    if (tmp == 0) {
        return 0;
    }
    return tmp * Lucas(n / MOD, m / MOD, MOD, pro, invpro);
}

template <typename S, S (*Multiply)(S, S), S (*Add)(S, S), S (*Zero)(),
          S (*One)(), bool (*IsZero)(S)>
class Matrix {
   public:
    Matrix(size_t rows, size_t cols) : rows_(rows), cols_(cols) {
        data_.assign(rows_, vector<S>(cols_, Zero()));
    }

    Matrix(const vector<vector<S>>& init) {
        if (init.empty()) {
            rows_ = cols_ = 0;
            return;
        }
        rows_ = init.size();
        cols_ = init[0].size();
        data_ = init;
        for (const auto& row : data_) {
            assert(row.size() == cols_);
        }
    }

    size_t rows() const { return rows_; }

    size_t cols() const { return cols_; }

    S& operator()(size_t i, size_t j) {
        assert(i < rows_ && j < cols_);
        return data_[i][j];
    }

    const S& operator()(size_t i, size_t j) const {
        assert(i < rows_ && j < cols_);
        return data_[i][j];
    }

    Matrix operator*(const Matrix& other) const {
        assert(cols_ == other.rows_);
        Matrix result(rows_, other.cols_);
        for (size_t i = 0; i < rows_; ++i) {
            for (size_t k = 0; k < cols_; ++k) {
                S aik = data_[i][k];
                if (IsZero(aik)) {
                    continue;
                }
                for (size_t j = 0; j < other.cols_; ++j) {
                    result(i, j) =
                        Add(result(i, j), Multiply(aik, other(k, j)));
                }
            }
        }
        return result;
    }

    Matrix pow(long long exponent) const {
        assert(rows_ == cols_);
        assert(exponent >= 0);
        Matrix result = Identity(rows_);
        Matrix base = *this;
        while (exponent > 0) {
            if (exponent & 1) {
                result = result * base;
            }
            base = base * base;
            exponent >>= 1;
        }
        return result;
    }

    static Matrix Identity(size_t n) {
        Matrix I(n, n);
        for (size_t i = 0; i < n; ++i) {
            I(i, i) = One();
        }
        return I;
    }

    void Print() const {
        for (size_t i = 0; i < rows_; ++i) {
            for (size_t j = 0; j < cols_; ++j) {
                cout << data_[i][j] << " \n"[j == cols_ - 1];
            }
        }
    }

   private:
    size_t rows_;
    size_t cols_;
    vector<vector<S>> data_;
};

modint Multiply(modint s1, modint s2) { return s1 * s2; }

modint Add(modint s1, modint s2) { return s1 + s2; }

modint Zero() { return 0; }

modint One() { return 1; }

bool IsZero(modint s) { return s == 0; }

void solveK100(int k, int b) {
    vector<vector<modint>> nums(k + 1, vector<modint>(k + 1, 0));
    nums[0][0] = nums[0][k] = 1;
    for (int i = 1; i <= k; ++i) {
        nums[i][i - 1] = 1;
    }
    Matrix<modint, Multiply, Add, Zero, One, IsZero> matrix(nums);
    cout << matrix.pow(b)(0, 0) << '\n';
}

void solve(int k, int b) {
    const int MOD = 1145141;
    vector<modint> pro(MOD), invpro(MOD);
    pro[0] = 1;
    for (int i = 1; i < MOD; ++i) {
        pro[i] = pro[i - 1] * i;
    }
    invpro[MOD - 1] = pro[MOD - 1].inv();
    for (int i = MOD - 2; i >= 0; --i) {
        invpro[i] = invpro[i + 1] * (i + 1);
    }

    modint ans = 0;
    for (int i = 0; i <= b; ++i) {
        if (b - 1LL * i * k < i) {
            break;
        }
        ans += Lucas(b - i * k, i, MOD, pro, invpro);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, b;
    cin >> k >> b;
    if (k == 0) {
        cout << modint(2).pow(b) << '\n';
        return 0;
    }
    if (k <= 100) {
        solveK100(k, b);
        return 0;
    }
    solve(k, b);

    return 0;
}