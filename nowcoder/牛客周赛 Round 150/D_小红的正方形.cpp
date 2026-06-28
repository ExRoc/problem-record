#include <bits/stdc++.h>
using namespace std;

struct KInfLine {
    int x, y1, y2;

    KInfLine() {}

    KInfLine(int x, int y1, int y2) : x(x), y1(min(y1, y2)), y2(max(y1, y2)) {}

    bool infPoint(const KInfLine& other) const {
        if (x != other.x) {
            return false;
        }
        int minY = max(y1, other.y1);
        int maxY = min(y2, other.y2);
        return minY < maxY;
    }
};

struct K0Line {
    int y, x1, x2;

    K0Line() {}

    K0Line(int y, int x1, int x2) : y(y), x1(min(x1, x2)), x2(max(x1, x2)) {}

    bool infPoint(const K0Line& other) const {
        if (y != other.y) {
            return false;
        }
        int minX = max(x1, other.x1);
        int maxX = min(x2, other.x2);
        return minX < maxX;
    }
};

struct Point {
    int x, y;

    Point() {}

    Point(int x, int y) : x(x), y(y) {}

    bool operator<(const Point& other) const {
        return x == other.x ? y < other.y : x < other.x;
    }
};

bool hasPoint(const KInfLine& l1, const KInfLine& l2) {
    if (l1.x != l2.x) {
        return false;
    }
    int minY = max(l1.y1, l2.y1);
    int maxY = min(l1.y2, l2.y2);
    return minY == maxY;
}

Point getPoint(const KInfLine& l1, const KInfLine& l2) {
    return Point(l1.x, max(l1.y1, l2.y1));
}

bool hasPoint(const K0Line& l1, const K0Line& l2) {
    if (l1.y != l2.y) {
        return false;
    }
    int minX = max(l1.x1, l2.x1);
    int maxX = min(l1.x2, l2.x2);
    return minX == maxX;
}

Point getPoint(const K0Line& l1, const K0Line& l2) {
    return Point(max(l1.x1, l2.x1), l1.y);
}

bool hasPoint(const KInfLine& l1, const K0Line& l2) {
    Point p(l1.x, l2.y);
    if (p.x < l2.x1 || p.x > l2.x2) {
        return false;
    }
    if (p.y < l1.y1 || p.y > l1.y2) {
        return false;
    }
    return true;
}

Point getPoint(const KInfLine& l1, const K0Line& l2) {
    return Point(l1.x, l2.y);
}

struct Node {
    int x1, y1, x2, y2;

    Node() {}

    Node(int x1, int y1, int x2, int y2)
        : x1(min(x1, x2)), y1(min(y1, y2)), x2(max(x1, x2)), y2(max(y1, y2)) {}

    vector<KInfLine> getKInfLines() {
        return {KInfLine(x1, y1, y2), KInfLine(x2, y1, y2)};
    }

    vector<K0Line> getK0Lines() {
        return {K0Line(y1, x1, x2), K0Line(y2, x1, x2)};
    }

    bool operator<(const Node& other) const { return false; }

    friend istream& operator>>(istream& in, Node& node) {
        in >> node.x1 >> node.y1 >> node.x2 >> node.y2;
        return in;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node nodes1, nodes2;
    cin >> nodes1 >> nodes2;
    vector<KInfLine> kInfLine1 = nodes1.getKInfLines();
    vector<KInfLine> kInfLine2 = nodes2.getKInfLines();
    vector<K0Line> k0Line1 = nodes1.getK0Lines();
    vector<K0Line> k0Line2 = nodes2.getK0Lines();
    for (const KInfLine& l1 : kInfLine1) {
        for (const KInfLine& l2 : kInfLine2) {
            if (l1.infPoint(l2)) {
                cout << "inf" << '\n';
                return 0;
            }
        }
    }
    for (const K0Line& l1 : k0Line1) {
        for (const K0Line& l2 : k0Line2) {
            if (l1.infPoint(l2)) {
                cout << "inf" << '\n';
                return 0;
            }
        }
    }
    set<Point> st;
    for (const KInfLine& l1 : kInfLine1) {
        for (const KInfLine& l2 : kInfLine2) {
            if (hasPoint(l1, l2)) {
                st.insert(getPoint(l1, l2));
            }
        }
        for (const K0Line& l2 : k0Line2) {
            if (hasPoint(l1, l2)) {
                st.insert(getPoint(l1, l2));
            }
        }
    }
    for (const K0Line& l1 : k0Line1) {
        for (const K0Line& l2 : k0Line2) {
            if (hasPoint(l1, l2)) {
                st.insert(getPoint(l1, l2));
            }
        }
        for (const KInfLine& l2 : kInfLine2) {
            if (hasPoint(l2, l1)) {
                st.insert(getPoint(l2, l1));
            }
        }
    }
    cout << st.size() << '\n';

    return 0;
}