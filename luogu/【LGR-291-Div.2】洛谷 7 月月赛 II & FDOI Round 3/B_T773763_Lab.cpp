#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long

struct RandomNumberGenerator {
   private:
    unsigned long long state;
    static constexpr unsigned long long a = 6364136223846793005ULL;
    static constexpr unsigned long long c = 1442695040888963407ULL;
    int k;
    vector<unsigned long long> p;

   public:
    explicit RandomNumberGenerator(unsigned long long seed, int k_,
                                   const vector<unsigned long long>& p_)
        : state(seed), k(k_), p(p_) {
        if (k > 32) k = 32;
        if (p.size() < static_cast<size_t>(k)) {
            p.resize(k, 0);
        }
    }
    unsigned long long next() {
        state = state * a + c;
        return state;
    }
    unsigned long long operator()() {
        unsigned long long result = 0;
        for (int i = 0; i < k; i++) {
            unsigned long long rand_val = next();
            if (rand_val < p[i]) {
                result |= (1ULL << i);
            }
        }
        return result;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, k, seed;
    cin >> n >> k >> seed;
    vector<int> p(k);
    for (int i = 0; i < k; i++) cin >> p[i];
    RandomNumberGenerator rnd(seed, k, p);
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) A[i] = rnd();
    for (int i = 1; i < n; ++i) {
        for (int j = 30; j > 0; --j) {
            if (((A[i + 1] >> j) & 1) == 0) {
                if ((A[i] >> j) != 0) {
                    int tmp = (1LL << j);
                    A[i + 1] |= tmp;
                    A[i] -= tmp;
                }
            }
        }
        A[i + 1] ^= (A[i] & 1);
    }
    cout << A[n] << '\n';

    return 0;
}
