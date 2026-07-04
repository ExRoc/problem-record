#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long X, Y, K;
        cin >> X >> Y >> K;
        map<long long, int> stepX, stepY;
        int step = 0;
        while (X != 0) {
            stepX[X] = step++;
            X /= K;
        }
        stepX[0] = step;
        step = 0;
        while (Y != 0) {
            stepY[Y] = step++;
            Y /= K;
        }
        stepY[0] = step;
        int ans = INT_MAX;
        for (const auto& [key, value] : stepX) {
            if (stepY.find(key) != stepY.end()) {
                ans = min(ans, value + stepY[key]);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}