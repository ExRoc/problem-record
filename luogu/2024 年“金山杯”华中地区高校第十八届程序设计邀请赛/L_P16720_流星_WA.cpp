#include <bits/stdc++.h>
using namespace std;

struct Node {
    long double x, y;
    int d;

    Node() {}

    Node(long double x, long double y, char d) : x(x), y(y) {
        if (d == 'U') {
            this->d = 0;
        } else if (d == 'D') {
            this->d = 1;
        } else if (d == 'L') {
            this->d = 2;
        } else {
            this->d = 3;
        }
    }

    bool operator<(const Node& other) const { return false; }
};

const vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

long double getS(long double t, const vector<Node>& nodes) {
    long double minX = LONG_LONG_MAX;
    long double maxX = LONG_LONG_MIN;
    long double minY = LONG_LONG_MAX;
    long double maxY = LONG_LONG_MIN;
    for (const Node& node : nodes) {
        long double x = node.x + dir[node.d][0] * t;
        long double y = node.y + dir[node.d][1] * t;
        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
    }
    return (maxX - minX) * (maxY - minY);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<Node> nodes;
    for (int i = 0; i < N; ++i) {
        int x, y;
        char d;
        cin >> x >> y >> d;
        nodes.push_back(Node(x, y, d));
    }
    long double low = 0;
    long double high = INT_MAX;
    while (high - low > 1e-12) {
        long double mid1 = low + (high - low) / 3;
        long double mid2 = high - (high - low) / 3;
        if (getS(mid1, nodes) > getS(mid2, nodes)) {
            low = mid1;
        } else {
            high = mid2;
        }
    }
    double S = getS(low, nodes);
    printf("%.10lf\n", S);

    return 0;
}