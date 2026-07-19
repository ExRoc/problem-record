#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;

    Point() {}

    Point(long long x, long long y) : x(x), y(y) {}
};

struct Vector {
    long long x, y;

    Vector() {}

    Vector(long long x, long long y) : x(x), y(y) {}
};

Vector operator-(const Point& a, const Point& b) {
    return Vector(a.x - b.x, a.y - b.y);
}

long long operator^(const Vector& a, const Vector& b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Point> ps(n);
    for (int i = 0; i < n; ++i) {
        cin >> ps[i].x >> ps[i].y;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            Vector v = ps[i] - ps[j];
            int cntL = 0, cntR = 0;
            for (int k = 0; k < n; ++k) {
                long long res = v ^ (ps[k] - ps[i]);
                if (res > 0) {
                    ++cntL;
                } else if (res < 0) {
                    ++cntR;
                }
            }
            if (cntL == cntR) {
                ++ans;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}