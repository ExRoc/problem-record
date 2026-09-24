#include <bits/stdc++.h>
using namespace std;

bool canRot90(const vector<string>& str, int N, int M) {
    if (N != M) {
        return false;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (str[j][M - i - 1] != str[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool canRot180(const vector<string>& str, int N, int M) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (str[N - i - 1][M - j - 1] != str[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool canRot270(const vector<string>& str, int N, int M) {
    if (N != M) {
        return false;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (str[N - j - 1][i] != str[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool canLRTurn(const vector<string>& str, int N, int M) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (str[i][M - j - 1] != str[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool canUDTurn(const vector<string>& str, int N, int M) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (str[N - i - 1][j] != str[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool canRot90LRTurn(const vector<string>& str, int N, int M) {
    if (N != M) {
        return false;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (str[j][i] != str[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool canRot90UDTurn(const vector<string>& str, int N, int M) {
    if (N != M) {
        return false;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (str[N - j - 1][M - i - 1] != str[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<string> str(N);
    for (int i = 0; i < N; ++i) {
        cin >> str[i];
    }
    int ans = 1;
    if (canRot90(str, N, M)) {
        ++ans;
    }
    if (canRot180(str, N, M)) {
        ++ans;
    }
    if (canRot270(str, N, M)) {
        ++ans;
    }
    if (canLRTurn(str, N, M)) {
        ++ans;
    }
    if (canUDTurn(str, N, M)) {
        ++ans;
    }
    if (canRot90LRTurn(str, N, M)) {
        ++ans;
    }
    if (canRot90UDTurn(str, N, M)) {
        ++ans;
    }
    cout << ans << '\n';

    return 0;
}