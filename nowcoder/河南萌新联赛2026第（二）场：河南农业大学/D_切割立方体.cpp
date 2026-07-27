#include <bits/stdc++.h>
using namespace std;

int id(int x, int y, int z, int w, int l, int h) {
    return x * l * h + y * h + z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w, x, h;
    cin >> w >> x >> h;
    vector<bool> vis(w * x * h, true);
    int q;
    cin >> q;
    while (q--) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int i = x1 - 1; i < x2; ++i) {
            for (int j = y1 - 1; j < y2; ++j) {
                for (int k = z1 - 1; k < z2; ++k) {
                    vis[id(i, j, k, w, x, h)] = false;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < x; ++j) {
            for (int k = 0; k < h; ++k) {
                if (vis[id(i, j, k, w, x, h)]) {
                    ++ans;
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}