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

typedef ModInt<1000000009> modint;

bool operator<(const modint& m1, const modint& m2) {
    return m1.value() < m2.value();
}

int id(char ch) { return ch - 'a' + 1; }

modint getHash(const string& s) {
    modint ret = 0;
    for (char ch : s) {
        ret = ret * 26 + id(ch);
    }
    return ret;
}

modint subStrHash(const vector<modint>& hashCodes, const vector<modint>& pw,
                  int l, int r) {
    if (r < l) {
        return 0;
    }
    if (l == 0) {
        return hashCodes[r];
    }
    return hashCodes[r] - hashCodes[l - 1] * pw[r - l + 1];
}

modint concatHash(modint m1, modint m2, int len2, const vector<modint>& pw) {
    return m1 * pw[len2] + m2;
}

const int maxcnt = 5000000 + 100;
const int ac_size = 26;

struct ac_auto {
    int cnt, root, head, tail;
    int tree[maxcnt][ac_size];
    int fail[maxcnt], que[maxcnt];
    bool flag[maxcnt];
    map<int, map<modint, vector<modint>>> hashCodeMaps[maxcnt];

    int create() {
        memset(tree[cnt], -1, sizeof(tree[cnt]));
        flag[cnt] = false;
        hashCodeMaps[cnt].clear();
        ++cnt;
        return cnt - 1;
    }

    void Init() {
        cnt = 0;
        root = create();
    }

    int id(char ch) { return ch - 'a'; }

    void insert(const string& str, modint hashCodeKey, modint hashCodeValue) {
        int pos = root;
        int len = str.length();
        for (int i = 0; i < len; ++i) {
            int w = id(str[i]);
            if (tree[pos][w] == -1) {
                tree[pos][w] = create();
            }
            pos = tree[pos][w];
        }
        flag[pos] = true;
        hashCodeMaps[pos][len][hashCodeKey].push_back(hashCodeValue);
    }

    void build() {
        fail[root] = root;
        que[0] = root;
        head = tail = 1;
        for (int i = 0; i < ac_size; ++i) {
            if (tree[root][i] == -1) {
                tree[root][i] = root;
            } else {
                fail[tree[root][i]] = root;
                que[tail++] = tree[root][i];
            }
        }
        while (head != tail) {
            int pos = que[head++];
            if (flag[fail[pos]]) {
                flag[pos] = true;
                if (hashCodeMaps[pos].size() > hashCodeMaps[fail[pos]].size()) {
                    swap(hashCodeMaps[pos], hashCodeMaps[fail[pos]]);
                }
                for (const auto& [len, value1] : hashCodeMaps[fail[pos]]) {
                    for (const auto& [hashCode, value2] : value1) {
                        for (modint valueCode : value2) {
                            hashCodeMaps[pos][len][hashCode].push_back(
                                valueCode);
                        }
                    }
                }
            }
            for (int i = 0; i < ac_size; ++i) {
                if (tree[pos][i] == -1) {
                    tree[pos][i] = tree[fail[pos]][i];
                } else {
                    fail[tree[pos][i]] = tree[fail[pos]][i];
                    que[tail++] = tree[pos][i];
                }
            }
        }
    }

    int query(const string& t1, const vector<modint>& hashCodeT1,
              const vector<modint>& pw, modint hashCodeT2) {
        int ans = 0;
        int pos = root;
        int lenT1 = t1.length();
        for (int i = 0; i < lenT1; ++i) {
            int w = id(t1[i]);
            pos = tree[pos][w];
            if (!flag[pos]) {
                continue;
            }
            for (const auto& [lenS1, value1] : hashCodeMaps[pos]) {
                if (i - lenS1 + 1 < 0) {
                    continue;
                }
                for (const auto& [hashCodeS1, value2] : value1) {
                    if (subStrHash(hashCodeT1, pw, i - lenS1 + 1, i) !=
                        hashCodeS1) {
                        continue;
                    }
                    for (const modint& hashCodeS2 : value2) {
                        modint hLeft = subStrHash(hashCodeT1, pw, 0, i - lenS1);
                        modint hMid = hashCodeS2;
                        modint hRight =
                            subStrHash(hashCodeT1, pw, i + 1, lenT1 - 1);
                        modint hashCodeChanged =
                            concatHash(concatHash(hLeft, hMid, lenS1, pw),
                                       hRight, lenT1 - i - 1, pw);
                        if (hashCodeChanged == hashCodeT2) {
                            ++ans;
                        }
                    }
                }
            }
        }
        return ans;
    }
} ac;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    const int maxn = 5000000;
    vector<modint> pw(maxn + 1);
    pw[0] = 1;
    for (int i = 1; i <= maxn; ++i) {
        pw[i] = pw[i - 1] * 26;
    }
    ac.Init();
    for (int i = 1; i <= n; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        ac.insert(s1, getHash(s1), getHash(s2));
    }
    ac.build();
    while (q--) {
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.length() != t2.length()) {
            cout << 0 << '\n';
            continue;
        }
        modint hashCodeT2 = getHash(t2);
        vector<modint> hashCodeT1(t1.length());
        modint hashCodeT1Tmp = 0;
        for (int i = 0; i < (int)t1.length(); ++i) {
            hashCodeT1Tmp = hashCodeT1Tmp * 26 + id(t1[i]);
            hashCodeT1[i] = hashCodeT1Tmp;
        }
        cout << ac.query(t1, hashCodeT1, pw, hashCodeT2) << '\n';
    }

    return 0;
}