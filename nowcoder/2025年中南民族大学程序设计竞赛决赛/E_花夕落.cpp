#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

struct Point {
    double x, y;

    Point() {}

    Point(double x, double y) : x(x), y(y) {}
};

struct Line {
    Point s, e;

    Line() {}

    Line(const Point& s, const Point& e) : s(s), e(e) {}
};

int sign(const double& x) {
    if (fabs(x) < eps) {
        return 0;
    }
    return x > 0 ? 1 : -1;
}

bool operator<(const Point& a, const Point& b) {
    if (sign(a.x - b.x) == 0) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

Point operator-(const Point& a, const Point& b) {
    return Point(a.x - b.x, a.y - b.y);
}

double operator^(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

double operator*(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}

double dis(const Point& a, const Point& b) { return sqrt((a - b) * (a - b)); }

vector<Point> convexHull(vector<Point>& ps, int n) {
    int top = 0;
    vector<Point> sta;
    sort(ps.begin(), ps.end());
    for (int i = 0; i < n; ++i) {
        while (top > 1 &&
               ((sta[top - 1] - sta[top - 2]) ^ (ps[i] - sta[top - 2])) <= 0) {
            sta.pop_back();
            --top;
        }
        sta.push_back(ps[i]);
        ++top;
    }
    int ttop = top;
    for (int i = n - 1; i >= 0; --i) {
        while (top > ttop &&
               ((sta[top - 1] - sta[top - 2]) ^ (ps[i] - sta[top - 2])) <= 0) {
            sta.pop_back();
            --top;
        }
        sta.push_back(ps[i]);
        ++top;
    }
    sta.pop_back();
    --top;
    return sta;
}

Point nearestPointToLineSeg(Point p, Line l) {
    Point result;
    double t = ((p - l.s) * (l.e - l.s)) / ((l.e - l.s) * (l.e - l.s));
    if (t >= 0 && t <= 1) {
        result.x = l.s.x + (l.e.x - l.s.x) * t;
        result.y = l.s.y + (l.e.y - l.s.y) * t;
    } else {
        if (dis(p, l.s) < dis(p, l.e)) {
            result = l.s;
        } else {
            result = l.e;
        }
    }
    return result;
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
    vector<Point> sta = convexHull(ps, n);
    double ans = 0;
    double minDis = 1e18;
    Point o(0, 0);
    for (int i = 0; i < (int)sta.size(); ++i) {
        Point p1 = sta[(i + 1) % sta.size()];
        Point p2 = sta[i];
        ans += dis(p1, p2);
        minDis = min(minDis, dis(nearestPointToLineSeg(o, Line(p1, p2)), o));
    }
    printf("%.10lf\n", ans + 2 * minDis);

    return 0;
}