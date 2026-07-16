#include <bits/stdc++.h>
using namespace std;

const vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

struct Node {
    __int128_t x, y;
    int d;

    Node() {}

    Node(__int128_t x, __int128_t y, char d) : x(x), y(y) {
        switch (d) {
            case 'U':
                this->d = 0;
                break;
            case 'D':
                this->d = 1;
                break;
            case 'L':
                this->d = 2;
                break;
            case 'R':
                this->d = 3;
                break;
            default:
                break;
        }
    }

    pair<__int128_t, __int128_t> go(__int128_t t) const {
        return make_pair(x + dir[d][0] * t, y + dir[d][1] * t);
    }

    bool operator<(const Node& other) const { return false; }
};

ostream& operator<<(ostream& out, __int128_t x) {
    if (x == 0) {
        out << 0;
        return out;
    }
    if (x < 0) {
        out << '-';
        x = -x;
    }
    string s;
    while (x != 0) {
        s.push_back((char)('0' + x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    out << s;
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<Node> nodes;
    const __int128_t INF = 0x3f3f3f3f3f3f3f3f;
    __int128_t maxL = -INF, maxR = -INF, maxUD = -INF;
    __int128_t minL = INF, minR = INF, minUD = INF;
    __int128_t maxU = -INF, maxD = -INF, maxLR = -INF;
    __int128_t minU = INF, minD = INF, minLR = INF;
    for (int i = 0; i < N; ++i) {
        long long xx, yy;
        char d;
        cin >> xx >> yy >> d;
        __int128_t x = xx << 1, y = yy << 1;
        nodes.push_back(Node(x, y, d));
        switch (d) {
            case 'U':
                maxUD = max(maxUD, x);
                minUD = min(minUD, x);
                maxU = max(maxU, y);
                minU = min(minU, y);
                break;
            case 'D':
                maxUD = max(maxUD, x);
                minUD = min(minUD, x);
                maxD = max(maxD, y);
                minD = min(minD, y);
                break;
            case 'L':
                maxL = max(maxL, x);
                minL = min(minL, x);
                maxLR = max(maxLR, y);
                minLR = min(minLR, y);
                break;
            case 'R':
                maxR = max(maxR, x);
                minR = min(minR, x);
                maxLR = max(maxLR, y);
                minLR = min(minLR, y);
                break;
            default:
                break;
        }
    }
    vector<__int128_t> ts;
    ts.push_back(0);
    if (maxL - maxUD > 0) {
        ts.push_back(maxL - maxUD);
    }
    if (maxUD - maxR > 0) {
        ts.push_back(maxUD - maxR);
    }
    if (maxL - maxR > 0) {
        ts.push_back((maxL - maxR) / 2);
    }
    if (minUD - minR > 0) {
        ts.push_back(minUD - minR);
    }
    if (minL - minUD > 0) {
        ts.push_back(minL - minUD);
    }
    if (minL - minR > 0) {
        ts.push_back((minL - minR) / 2);
    }
    if (maxD - maxLR > 0) {
        ts.push_back(maxD - maxLR);
    }
    if (maxLR - maxU > 0) {
        ts.push_back(maxLR - maxU);
    }
    if (maxD - maxU > 0) {
        ts.push_back((maxD - maxU) / 2);
    }
    if (minLR - minU > 0) {
        ts.push_back(minLR - minU);
    }
    if (minD - minLR > 0) {
        ts.push_back(minD - minLR);
    }
    if (minD - minU > 0) {
        ts.push_back((minD - minU) / 2);
    }
    __int128_t ans = LONG_LONG_MAX;
    for (__int128_t t : ts) {
        __int128_t minX = INF, minY = INF;
        __int128_t maxX = -INF, maxY = -INF;
        for (const Node& node : nodes) {
            pair<__int128_t, __int128_t> p = node.go(t);
            minX = min(minX, p.first);
            maxX = max(maxX, p.first);
            minY = min(minY, p.second);
            maxY = max(maxY, p.second);
        }
        ans = min(ans, (maxX - minX) * (maxY - minY));
    }
    cout << ans / 4;
    switch (ans % 4) {
        case 1:
            cout << ".25" << '\n';
            break;
        case 2:
            cout << ".5" << '\n';
            break;
        case 3:
            cout << ".75" << '\n';
            break;
        default:
            break;
    }

    return 0;
}