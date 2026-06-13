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

typedef Matrix<modint, Multiply, Add, Zero, One, IsZero> matrix;

modint solve(int n, int m) {
    modint mTop = modint(2).pow(m);
    vector<vector<modint>> m1Tmp = {{0, mTop - 1}, {1, mTop - 2}};
    vector<vector<modint>> m2Tmp = {{mTop - 1, 0}, {0, mTop - 1}};
    matrix m1(m1Tmp), m2(m2Tmp);
    if (n % 2 == 0) {
        swap(m1, m2);
    }
    matrix m3 = m2 * m1;
    matrix mRes = m3.pow((n - 1) / 2);
    if (n % 2 == 1) {
        return mRes(0, 0);
    }
    return mRes(0, 1);
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << solve(n, m) + solve(n + 1, m) << '\n';
    }

    return 0;
}