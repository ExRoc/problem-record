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

    T Sum(int l, int r) {
        assert(0 <= l && l <= r && r <= n_);
        return Sum(r) - Sum(l);
    }

   private:
    int n_;
    vector<T> data_;

    T Sum(int r) {
        T s = 0;
        while (r > 0) {
            s += data_[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

long long solve(vector<long long> num) {
    int n = num.size() - 1;
    long long s = 0;
    vector<long long> sand;
    sand.push_back(0);
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0) {
            s -= num[i];
        } else {
            s += num[i];
        }
        sand.push_back(s);
    }
    sort(sand.begin(), sand.end());
    sand.erase(unique(sand.begin(), sand.end()), sand.end());
    FenwickTree<long long> sum(sand.size() + 2);
    long long ans = 0;
    for (int i = n; i > 0; --i) {
        if (i % 2 == 0) {
            s += num[i];
        } else {
            long long ttmp =
                lower_bound(sand.begin(), sand.end(), s) - sand.begin() + 1;
            sum.Add(ttmp, 1);
            s -= num[i];
            long long tmp =
                lower_bound(sand.begin(), sand.end(), s) - sand.begin() + 1;
            ans += sum.Sum(tmp + 1, sand.size() + 2);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int T, n;
    vector<long long> num;
    cin >> T;
    while (T--) {
        cin >> n;
        num.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
        }
        long long ans = solve(num);
        vector<long long>::iterator it = num.begin();
        ++it;
        num.erase(it);
        ans += solve(num);
        cout << ans << endl;
    }

    return 0;
}