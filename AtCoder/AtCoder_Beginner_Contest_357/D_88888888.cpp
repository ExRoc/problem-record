#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int matrix_size = 2;
const int MOD = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= MOD) {
        return a - MOD;
    }
    return a;
}

struct Matrix {
    int size;
    int num[matrix_size][matrix_size];

    void operator=(const Matrix& m) {
        for (int i = 0; i < size; ++i) {
            memcpy(num[i], m.num[i], sizeof(int) * size);
        }
    }

    void Init() {
        for (int i = 0; i < size; ++i) {
            memset(num[i], 0, sizeof(int) * size);
            num[i][i] = 1;
        }
    }

    void Set(LL s) {
        size = 2;
        LL tmp = s;
        int dig = 0;
        while (tmp != 0) {
            ++dig;
            tmp /= 10;
        }
        tmp = 1;
        for (int i = 0; i < dig; ++i) {
            tmp = tmp * 10 % MOD;
        }
        num[0][0] = tmp;
        num[0][1] = 1;
        num[1][0] = 0;
        num[1][1] = 1;
    }

    void operator*=(const Matrix& m) {
        static Matrix ans;
        ans.size = size;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                ans.num[i][j] = 0;
                for (int k = 0; k < size; ++k) {
                    ans.num[i][j] =
                        add(ans.num[i][j], (LL)num[i][k] * m.num[k][j] % MOD);
                }
            }
        }
        (*this) = ans;
    }

    void fast_pow(LL n) {
        static Matrix ans;
        ans.size = size;
        for (ans.Init(); n != 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans *= (*this);
            }
            (*this) *= (*this);
        }
        (*this) = ans;
    }
};

LL n;
Matrix matrix;

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    matrix.Set(n);
    matrix.fast_pow(n);
    LL tmp = matrix.num[0][1];
    tmp = tmp * (n % MOD) % MOD;
    cout << tmp << endl;

    return 0;
}
