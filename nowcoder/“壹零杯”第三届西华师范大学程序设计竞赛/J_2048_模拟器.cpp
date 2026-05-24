#include <bits/stdc++.h>
using namespace std;

bool in(int x, int y, int N) { return x >= 0 && x < N && y >= 0 && y < N; }

void change(int x, int y, int N, pair<int, int> dir, vector<vector<int>>& A) {
    int dx = dir.first;
    int dy = dir.second;
    while (in(x, y, N)) {
        x += dx;
        y += dy;
    }
    int xx = x;
    int yy = y;
    x -= dx;
    y -= dy;
    int last = 0;
    for (int i = 0; i < N; ++i) {
        xx -= dx;
        yy -= dy;
        if (A[xx][yy] == 0) {
            continue;
        }
        if (last == 0) {
            A[x][y] = A[xx][yy];
            last = A[x][y];
            continue;
        }
        if (last != A[xx][yy]) {
            x -= dx;
            y -= dy;
            A[x][y] = A[xx][yy];
            last = A[x][y];
            continue;
        }
        ++A[x][y];
        last = 0;
        x -= dx;
        y -= dy;
    }
    if (last != 0) {
        x -= dx;
        y -= dy;
    }
    while (in(x, y, N)) {
        A[x][y] = 0;
        x -= dx;
        y -= dy;
    }
}

void print(int N, vector<vector<int>>& A) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (A[i][j] == 0) {
                cout << 0 << " ";
            } else {
                cout << (1 << (A[i][j] - 1)) << " ";
            }
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int tmp;
            cin >> tmp;
            while (tmp > 0) {
                ++A[i][j];
                tmp >>= 1;
            }
        }
    }
    map<char, int> dirIdx;
    dirIdx['L'] = 0;
    dirIdx['R'] = 1;
    dirIdx['U'] = 2;
    dirIdx['D'] = 3;
    const vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    string S;
    cin >> S;
    for (char ch : S) {
        int idx = dirIdx[ch];
        if (idx <= 1) {
            for (int i = 0; i < N; ++i) {
                change(i, 0, N, dir[idx], A);
            }
        } else {
            for (int j = 0; j < N; ++j) {
                change(0, j, N, dir[idx], A);
            }
        }
    }
    print(N, A);

    return 0;
}