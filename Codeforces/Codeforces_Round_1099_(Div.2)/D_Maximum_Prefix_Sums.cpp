#include <bits/stdc++.h>
using namespace std;

int findNext(int idx, int n, const vector<long long>& c) {
    for (int i = idx + 1; i <= n; ++i) {
        if (c[i] != c[i - 1]) {
            return i;
        }
    }
    return n + 1;
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = ' ' + s;
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        vector<long long> c(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> c[i];
        }
        if (s[1] == '1' && a[1] != c[1]) {
            cout << "No" << '\n';
            continue;
        }
        bool flag = true;
        for (int i = 2; i <= n; ++i) {
            if (c[i] < c[i - 1]) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            cout << "No" << '\n';
            continue;
        }
        vector<long long> suma(n + 1, 0), sums(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            suma[i] = suma[i - 1] + a[i];
            sums[i] = sums[i - 1] + s[i] - '0';
        }
        const long long INF = 3e11;
        int next = n + 1;
        long long sum = 0;
        for (int i = 1; i <= n; i = next) {
            if (s[i] == '0') {
                a[i] = c[i] - sum;
            }
            sum = c[i];
            next = findNext(i, n, c);
            if (next == n + 1) {
                for (int j = i + 1; j < next; ++j) {
                    if (s[j] == '0') {
                        a[j] = -INF;
                    }
                }
                continue;
            }
            for (int j = i + 1; j < next; ++j) {
                if (s[j] == '0') {
                    if (sums[next] - sums[j] < next - j) {
                        a[j] = -INF;
                    } else {
                        a[j] = c[next] - (suma[next] - suma[j]) - sum;
                    }
                }
                sum += a[j];
            }
        }
        sum = 0;
        long long mxsum = -INF;
        flag = true;
        for (int i = 1; i <= n; ++i) {
            sum += a[i];
            mxsum = max(mxsum, sum);
            if (mxsum != c[i]) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            cout << "No" << '\n';
            continue;
        }
        cout << "Yes" << '\n';
        for (int i = 1; i <= n; ++i) {
            cout << a[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}