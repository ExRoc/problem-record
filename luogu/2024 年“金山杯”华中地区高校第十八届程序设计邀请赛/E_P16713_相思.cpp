#include <bits/stdc++.h>
using namespace std;

class PrimeSieve {
   public:
    explicit PrimeSieve(int max_n) : max_n_(max_n) {
        is_prime_.resize(max_n_ + 1, true);
        if (max_n_ >= 0) {
            is_prime_[0] = false;
        }
        if (max_n_ >= 1) {
            is_prime_[1] = false;
        }

        for (int i = 2; i <= max_n_; ++i) {
            if (is_prime_[i]) {
                primes_.push_back(i);
            }
            for (int p : primes_) {
                long long num = 1LL * i * p;
                if (num > max_n_) {
                    break;
                }
                is_prime_[num] = false;
                if (i % p == 0) {
                    break;
                }
            }
        }
    }

    bool IsPrime(int x) const {
        assert(x >= 0 && x <= max_n_);
        return is_prime_[x];
    }

    const vector<int>& GetPrimes() const { return primes_; }

   private:
    int max_n_;
    vector<bool> is_prime_;
    vector<int> primes_;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int maxn = 200000;
    PrimeSieve sieve(maxn);
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    for (int i = l1; i <= r1; ++i) {
        bool hasPrime = false;
        for (int j = l2; j <= r2; ++j) {
            if (sieve.IsPrime(i + j)) {
                hasPrime = true;
                break;
            }
        }
        if (!hasPrime) {
            cout << "Burnside" << '\n';
            return 0;
        }
    }
    cout << "Edisnrub" << '\n';

    return 0;
}