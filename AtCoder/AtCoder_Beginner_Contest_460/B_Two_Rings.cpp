#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        long long X1, Y1, R1, X2, Y2, R2;
        cin >> X1 >> Y1 >> R1 >> X2 >> Y2 >> R2;
        long long dis2 = (X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2);
        long long disTmp2 = (R1 + R2) * (R1 + R2);
        long long disTmp3 = (R1 - R2) * (R1 - R2);
        if (dis2 <= disTmp2 && dis2 >= disTmp3) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }

    return 0;
}