#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
struct Point {
    LL x, y;
    Point() {}
    Point(LL xx, LL yy) {
        x = xx;
        y = yy;
    }
};

Point operator-(const Point& a, const Point& b) {
    return Point(a.x - b.x, a.y - b.y);
}

LL operator*(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}

Point p[3];

int main() {
    ios::sync_with_stdio(false);

    for (int i = 0; i < 3; ++i) {
        cin >> p[i].x >> p[i].y;
    }
    for (int i = 0; i < 3; ++i) {
        if ((p[(i + 1) % 3] - p[i]) * (p[(i + 2) % 3] - p[i]) == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
