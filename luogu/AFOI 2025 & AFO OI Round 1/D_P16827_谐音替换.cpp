#include <bits/stdc++.h>
using namespace std;

template <class T>
struct FenwickTree {
   public:
    FenwickTree() : n_(0) {}
    explicit FenwickTree(int n) : n_(n), data_(n) {}

    void Add(int p, T x) {
        assert(0 <= p && p < n_);
        ++p;
        while (p <= n_) {
            data_[p - 1] += x;
            p += p & -p;
        }
    }

    T Sum(int l, int r) const {
        assert(0 <= l && l <= r && r <= n_);
        return Sum(r) - Sum(l);
    }

    void Clear() { fill(data_.begin(), data_.end(), T{}); }

    void Swap(FenwickTree& other) noexcept {
        swap(n_, other.n_);
        swap(data_, other.data_);
    }

   private:
    int n_;
    vector<T> data_;

    T Sum(int r) const {
        T s = 0;
        while (r > 0) {
            s += data_[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

int id(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - 'a' + 1;
    }
    return ch - 'A' + 27;
}

struct HashCode {
    static const int MOD1 = 105110107;
    static const int MOD2 = 1145142023;
    long long hashCode1, hashCode2;

    HashCode() : hashCode1(0), hashCode2(0) {}

    HashCode(long long _hashCode1, long long _hashCode2)
        : hashCode1(_hashCode1), hashCode2(_hashCode2) {}

    HashCode(long long x) : hashCode1(x % MOD1), hashCode2(x % MOD2) {
        if (hashCode1 < 0) {
            hashCode1 += MOD1;
        }
        if (hashCode2 < 0) {
            hashCode2 += MOD2;
        }
    }

    friend HashCode operator*(const HashCode& h1, const HashCode& h2) {
        return HashCode(h1.hashCode1 * h2.hashCode1 % HashCode::MOD1,
                        h1.hashCode2 * h2.hashCode2 % HashCode::MOD2);
    }

    friend HashCode operator+(const HashCode& h1, const HashCode& h2) {
        return HashCode((h1.hashCode1 + h2.hashCode1) % HashCode::MOD1,
                        (h1.hashCode2 + h2.hashCode2) % HashCode::MOD2);
    }

    friend HashCode operator-(const HashCode& h1, const HashCode& h2) {
        return HashCode(
            (h1.hashCode1 - h2.hashCode1 + HashCode::MOD1) % HashCode::MOD1,
            (h1.hashCode2 - h2.hashCode2 + HashCode::MOD2) % HashCode::MOD2);
    }

    friend bool operator<(const HashCode& h1, const HashCode h2) {
        return h1.hashCode1 == h2.hashCode1 ? h1.hashCode2 < h2.hashCode2
                                            : h1.hashCode1 < h2.hashCode1;
    }

    friend bool operator==(const HashCode& h1, const HashCode& h2) {
        return h1.hashCode1 == h2.hashCode1 && h1.hashCode2 == h2.hashCode2;
    }
};

namespace std {
template <>
struct hash<HashCode> {
    size_t operator()(const HashCode& h) const {
        size_t h1 = hash<long long>{}(h.hashCode1);
        size_t h2 = hash<long long>{}(h.hashCode2);
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};
}  // namespace std

HashCode getHashCode(const vector<HashCode>& hashCode, int l, int r,
                     const vector<HashCode>& p) {
    if (r < l) {
        return 0;
    }
    if (l == 0) {
        return hashCode[r];
    }
    return hashCode[r] - hashCode[l - 1] * p[r - l + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int maxn = 1e6;
    vector<HashCode> p(maxn + 1);
    p[0] = 1;
    for (int i = 1; i <= maxn; ++i) {
        p[i] = p[i - 1] * 52;
    }
    int n, m;
    cin >> n >> m;
    unordered_set<HashCode> prefixHashCodeSet, suffixHashCodeSet, hashCodeSet;
    for (int i = 0; i < n; ++i) {
        string S;
        cin >> S;
        int len = S.length();
        HashCode hashCode;
        for (char ch : S) {
            hashCode = hashCode * 52 + id(ch);
            prefixHashCodeSet.insert(hashCode);
            hashCodeSet.insert(hashCode);
        }
        hashCode = 0;
        for (int i = len - 1; i >= 0; --i) {
            hashCode = hashCode + id(S[i]) * p[len - 1 - i];
            suffixHashCodeSet.insert(hashCode);
            hashCodeSet.insert(hashCode);
        }
    }
    while (m--) {
        string T;
        cin >> T;
        int len = T.length();
        T = ' ' + T;
        vector<HashCode> hashCodeT(len + 1, 0);
        for (int i = 1; i <= len; ++i) {
            hashCodeT[i] = hashCodeT[i - 1] * 52 + id(T[i]);
        }
        FenwickTree<int> prefixSum(len + 1);
        for (int i = 1; i <= len; ++i) {
            if (hashCodeSet.find(hashCodeT[i]) != hashCodeSet.end()) {
                prefixSum.Add(i, 1);
            }
        }
        vector<int> suffixSum(len + 2, 0);
        for (int i = len; i >= 1; --i) {
            suffixSum[i] = suffixSum[i + 1];
            if (hashCodeSet.find(getHashCode(hashCodeT, i, len, p)) !=
                hashCodeSet.end()) {
                ++suffixSum[i];
            }
        }
        long long ans = 0;
        vector<vector<int>> bsearchBeginIdxs(len + 1);
        for (int idx1 = 2; idx1 < len; ++idx1) {
            if (prefixSum.Sum(idx1 - 1, idx1) == 0) {
                continue;
            }
            int high = len;
            int low = idx1 - 1;
            while (high - low > 1) {
                int mid = (high + low) >> 1;
                if (prefixHashCodeSet.find(getHashCode(
                        hashCodeT, idx1, mid, p)) != prefixHashCodeSet.end()) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
            if (low < idx1) {
                continue;
            }
            bsearchBeginIdxs[low].push_back(idx1);
            ans += suffixSum[idx1 + 1] - suffixSum[low + 2];
        }
        for (int idx2 = len - 1; idx2 > 1; --idx2) {
            for (int idx : bsearchBeginIdxs[idx2]) {
                prefixSum.Add(idx - 1, -1);
            }
            if (suffixSum[idx2 + 1] - suffixSum[idx2 + 2] == 0) {
                continue;
            }
            int high = idx2 + 1;
            int low = 1;
            while (high - low > 1) {
                int mid = (high + low) >> 1;
                if (suffixHashCodeSet.find(getHashCode(
                        hashCodeT, mid, idx2, p)) != suffixHashCodeSet.end()) {
                    high = mid;
                } else {
                    low = mid;
                }
            }
            if (high > idx2) {
                continue;
            }
            ans += prefixSum.Sum(high - 1, idx2);
        }
        cout << ans << '\n';
    }

    return 0;
}