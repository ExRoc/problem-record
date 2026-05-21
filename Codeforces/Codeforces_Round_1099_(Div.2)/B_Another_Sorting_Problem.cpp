#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1), aa(n + 1);
        long long k = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            aa[i] = a[i];
            if (i != 1) {
                if (aa[i] < aa[i - 1]) {
                    aa[i] += k;
                    if (aa[i] < aa[i - 1]) {
                        k += aa[i - 1] - aa[i];
                        aa[i - 1] += k;
                    }
                }
            }
        }
        for (int i = 2; i <= n; ++i) {
            if (a[i] < a[i - 1]) {
                a[i] += k;
            }
        }
        bool flag = true;
        for (int i = 2; i <= n; ++i) {
            if (a[i] < a[i - 1]) {
                flag = false;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }

    return 0;
}