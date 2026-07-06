#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int idxDotA = a.find('.');
    int idxDotB = b.find('.');
    if (idxDotA < idxDotB) {
        for (int i = 0; i < idxDotB - idxDotA; ++i) {
            b = b.substr(1, b.length());
        }
    } else {
        for (int i = 0; i < idxDotA - idxDotB; ++i) {
            a = a.substr(1, a.length());
        }
    }
    int ans = 0;
    int c = 0;
    for (int i = 0; i < (int)max(a.length(), b.length()); ++i) {
        if (a[i] == '.') {
            continue;
        }
        int aa, bb;
        if (i >= a.length()) {
            aa = 0;
        } else {
            aa = a[i] - '0';
        }
        if (i >= b.length()) {
            bb = 0;
        } else {
            bb = b[i] - '0';
        }
        c = (aa + bb + c) / 10;
        ans += c;
    }
    cout << ans << '\n';

    return 0;
}