#include <bits/stdc++.h>
using namespace std;

struct Point {
    int idx, x, y;
    static int W, H;

    Point() {}

    Point(int idx, int x, int y) : idx(idx), x(x), y(y) {}

    int getBoardId() const {
        if (y == 0) {
            return 0;
        }
        if (x == W) {
            return 1;
        }
        if (y == H) {
            return 2;
        }
        return 3;
    }

    bool operator<(const Point& other) const {
        int boardId = getBoardId();
        int otherBoardId = other.getBoardId();
        if (boardId != otherBoardId) {
            return boardId < otherBoardId;
        }
        switch (boardId) {
            case 0:
                return x < other.x;
            case 1:
                return y < other.y;
            case 2:
                return x > other.x;
        }
        return y > other.y;
    }
};

int Point::W = 0;
int Point::H = 0;

bool inBoard(int X, int Y, int W, int H) {
    return X == 0 || X == W || Y == 0 || Y == H;
}

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int W, H;
    cin >> W >> H;
    Point::W = W;
    Point::H = H;
    int N;
    cin >> N;
    vector<Point> points;
    for (int i = 0; i < N; ++i) {
        int X1, Y1, X2, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;
        if (inBoard(X1, Y1, W, H) && inBoard(X2, Y2, W, H)) {
            points.push_back(Point(i, X1, Y1));
            points.push_back(Point(i, X2, Y2));
        }
    }
    sort(points.begin(), points.end());
    stack<int> sta;
    for (const Point point : points) {
        if (sta.empty()) {
            sta.push(point.idx);
            continue;
        }
        if (sta.top() == point.idx) {
            sta.pop();
        } else {
            sta.push(point.idx);
        }
    }
    if (sta.empty()) {
        cout << "Y" << '\n';
    } else {
        cout << "N" << '\n';
    }

    return 0;
}