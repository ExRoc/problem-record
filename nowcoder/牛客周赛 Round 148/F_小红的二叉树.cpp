#include <bits/stdc++.h>
using namespace std;

long long getLeft(int step, long long n, long long x) {
    long long l = x << 1;
    long long r = x << 1;
    if (l > n) {
        return 0;
    }
    for (int i = 2; i <= step; ++i) {
        l <<= 1;
        r = (r << 1) | 1;
        if (l > n) {
            return 0;
        }
    }
    r = min(r, n);
    return r - l + 1;
}

long long getRight(int step, long long n, long long x) {
    long long l = (x << 1) | 1;
    long long r = (x << 1) | 1;
    if (l > n) {
        return 0;
    }
    for (int i = 2; i <= step; ++i) {
        l <<= 1;
        r = (r << 1) | 1;
        if (l > n) {
            return 0;
        }
    }
    r = min(r, n);
    return r - l + 1;
}

long long getUp(int step, long long n, long long x) {
    long long xTmp = x;
    long long ans = 0;
    for (int i = 1; i <= step; ++i) {
        if (xTmp == 1) {
            return ans;
        }
        if (xTmp % 2 == 0) {
            ans += getRight(step - i, n, xTmp >> 1);
        } else {
            ans += getLeft(step - i, n, xTmp >> 1);
        }
        xTmp >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    long long n, x;
    cin >> n >> x;
    int bitUp = 50;
    long long ans = 1;
    for (int i = 1; i < bitUp; ++i) {
        long long left = getLeft(i, n, x);
        long long right = getRight(i, n, x);
        long long up = getUp(i, n, x);
        ans += left * right + (left + right) * up;
    }
    cout << ans << '\n';

    return 0;
}