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

void add(unordered_map<int, pair<int, int>>& idxs, int x, int idx) {
    unordered_map<int, pair<int, int>>::iterator it = idxs.find(x);
    if (it == idxs.end()) {
        idxs[x] = make_pair(idx, idx);
        return;
    }
    (it->second).second = idx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int maxn = 1e7;
    PrimeSieve sieve(maxn);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        unordered_map<int, pair<int, int>> idxs;
        for (int i = 1; i <= n; ++i) {
            int a;
            cin >> a;
            for (int j = 2; j <= a / j; ++j) {
                if (a % j == 0) {
                    while (a % j == 0) {
                        a /= j;
                    }
                    add(idxs, j, i);
                }
                if (sieve.IsPrime(a)) {
                    break;
                }
            }
            if (a != 1) {
                add(idxs, a, i);
            }
        }
        vector<int> sumFirst(n + 1, 0), sumSecond(n + 1, 0);
        for (const auto& [x, lr] : idxs) {
            ++sumFirst[lr.first];
            ++sumSecond[lr.second];
        }
        for (int i = 1; i <= n; ++i) {
            sumFirst[i] += sumFirst[i - 1];
            sumSecond[i] += sumSecond[i - 1];
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << sumFirst[r] - sumSecond[l - 1] << '\n';
        }
    }

    return 0;
}