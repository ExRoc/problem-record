#include <bits/stdc++.h>
using namespace std;

struct Point {
    int pos;
    long long p;

    Point() {}

    Point(int pos, long long p) : pos(pos), p(p) {}

    bool operator<(const Point& other) const {
        return pos == other.pos ? p < other.p : pos < other.pos;
    }
};

int find(vector<int>& fa, int x) {
    return fa[x] == x ? x : fa[x] = find(fa, fa[x]);
}

void unit(vector<int>& fa, vector<long long>& p, int x, int y) {
    x = find(fa, x);
    y = find(fa, y);
    if (x != y) {
        fa[x] = y;
        p[y] += p[x];
    }
}

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int F, N;
    cin >> F >> N;
    vector<int> k(N);
    vector<long long> p(N);
    map<int, int> idx;
    for (int i = 0; i < N; ++i) {
        cin >> k[i] >> p[i];
        idx[k[i]] = i;
    }
    vector<int> fa(N);
    for (int i = 0; i < N; ++i) {
        fa[i] = i;
    }
    vector<bool> accept(N, false);
    vector<int> a(N), t(N);
    for (int i = 0; i < N; ++i) {
        char ch;
        cin >> ch;
        if (ch == 'A') {
            cin >> a[i] >> t[i];
            accept[i] = true;
        }
        if (ch == 'T') {
            int x;
            cin >> x;
            if (idx.find(x) == idx.end()) {
                continue;
            }
            unit(fa, p, i, idx[x]);
        }
    }
    vector<Point> points;
    for (int i = 0; i < N; ++i) {
        if (accept[i]) {
            points.push_back(Point(a[i], p[i]));
            points.push_back(Point(a[i] + t[i], -p[i]));
        }
    }
    sort(points.begin(), points.end());
    long long ans = 0;
    long long tmp = 0;
    for (const Point& point : points) {
        tmp += point.p;
        ans = max(ans, tmp);
    }
    cout << ans << '\n';

    return 0;
}