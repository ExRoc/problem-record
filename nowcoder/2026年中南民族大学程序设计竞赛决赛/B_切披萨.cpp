#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n == 1) {
            printf("0\n1 1\n");
            continue;
        }
        int k = (n + 1) / 2;
        printf("%d\n", k);
        for (int i = 0; i < k; ++i) {
            printf("%.9lf ", 360.0 / n * i);
        }
        printf("\n");
        if (n % 2 == 0) {
            for (int i = 1; i <= n; ++i) {
                printf("1 %d\n", i);
            }
            continue;
        }
        for (int i = 1; i < n; ++i) {
            if (i <= n / 2) {
                printf("1 %d\n", i);
            } else {
                printf("1 %d\n", i + 1);
            }
        }
        printf("2 %d %d\n", k, n + 1);
    }

    return 0;
}