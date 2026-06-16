#include <bits/stdc++.h>
using namespace std;

struct Vector {
    long long x, y;
};

Vector operator-(const Vector& a, const Vector& b) {
    return {a.x - b.x, a.y - b.y};
}

long long operator^(const Vector& a, const Vector& b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<Vector> vectors(n);
        for (int i = 0; i < n; ++i) {
            cin >> vectors[i].x >> vectors[i].y;
        }
        vector<vector<long long>> S(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) {
            int idx = i;
            for (int j = (i + 2) % n; j != i; j = (j + 1) % n) {
                int next = (idx + 1) % n;
                while (idx != j && abs((vectors[next] - vectors[i]) ^
                                       (vectors[j] - vectors[i])) >
                                       abs((vectors[idx] - vectors[i]) ^
                                           (vectors[j] - vectors[i]))) {
                    idx = next;
                    next = (idx + 1) % n;
                }
                S[i][j] =
                    (vectors[idx] - vectors[i]) ^ (vectors[j] - vectors[i]);
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int nexti = (i + 1) % n;
            for (int j = (nexti + 2) % n; (j + 2) % n != i; j = (j + 1) % n) {
                int nextj = (j + 1) % n;
                ans = max(ans, S[nextj][i] + S[nexti][j]);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}