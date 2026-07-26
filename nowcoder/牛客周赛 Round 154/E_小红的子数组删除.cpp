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

long long find(int cnt, FenwickTree<int>& sum, const vector<long long>& sand) {
    int low = -1;
    int high = sand.size() - 1;
    while (high - low > 1) {
        int mid = (high + low) >> 1;
        if (sum.Sum(0, mid + 1) >= cnt) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return sand[high];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, x;
    cin >> n >> k >> x;
    if (n == k) {
        cout << 0 << '\n';
        return 0;
    }
    x <<= 1;
    vector<long long> sand;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] <<= 1;
        sand.push_back(a[i]);
    }
    sort(sand.begin(), sand.end());
    sand.erase(unique(sand.begin(), sand.end()), sand.end());
    FenwickTree<int> sum(sand.size());
    for (int i = k; i < n; ++i) {
        sum.Add(lower_bound(sand.begin(), sand.end(), a[i]) - sand.begin(), 1);
    }
    int ans = 0;
    for (int i = 0; i + k - 1 < n; ++i) {
        if ((n - k) % 2 == 1) {
            long long mid = find((n - k + 1) / 2, sum, sand);
            if (mid == x) {
                ++ans;
            }
        } else {
            long long mid1 = find((n - k) / 2, sum, sand);
            long long mid2 = find((n - k) / 2 + 1, sum, sand);
            if ((mid1 + mid2) / 2 == x) {
                ++ans;
            }
        }
        sum.Add(lower_bound(sand.begin(), sand.end(), a[i]) - sand.begin(), 1);
        if (i + k < n) {
            sum.Add(
                lower_bound(sand.begin(), sand.end(), a[i + k]) - sand.begin(),
                -1);
        }
    }
    cout << ans << '\n';

    return 0;
}