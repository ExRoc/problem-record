#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        printf("%.5lf\n", 1.0 * n / (n + m));
    }

    return 0;
}