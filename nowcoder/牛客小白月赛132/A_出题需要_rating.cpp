#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int rating = 1000;
    vector<int> cnt(7);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        rating += x;
        if (rating < 700) {
            ++cnt[0];
        } else if (rating < 1100) {
            ++cnt[1];
        } else if (rating < 1500) {
            ++cnt[2];
        } else if (rating < 2000) {
            ++cnt[3];
        } else if (rating < 2400) {
            ++cnt[4];
        } else if (rating < 2800) {
            ++cnt[5];
        } else {
            ++cnt[6];
        }
    }
    for (int x : cnt) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}