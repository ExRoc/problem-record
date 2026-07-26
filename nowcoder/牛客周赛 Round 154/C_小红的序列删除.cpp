#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k, const string& s, char d1, char d2) {
    map<char, int> cnt;
    for (char ch : s) {
        ++cnt[ch];
    }
    int cut = min(cnt[d1], k);
    cnt[d1] -= cut;
    k -= cut;
    cut = min(cnt[d2], k);
    cnt[d2] -= cut;
    k -= cut;
    return abs(cnt['U'] - cnt['D']) + abs(cnt['L'] - cnt['R']) - k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string dir = "ULDRU";
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    char d1, d2;
    for (int i = 0; i < 4; ++i) {
        int tmp = solve(n, k, s, dir[i], dir[i + 1]);
        if (tmp > ans) {
            ans = tmp;
            d1 = dir[i];
            d2 = dir[i + 1];
        }
    }
    map<char, int> cnt;
    for (char ch : s) {
        ++cnt[ch];
    }
    int cut = min(cnt[d1], k);
    cnt[d1] -= cut;
    k -= cut;
    cut = min(cnt[d2], k);
    cnt[d2] -= cut;
    k -= cut;
    for (auto& [key, value] : cnt) {
        cut = min(value, k);
        k -= cut;
        value -= cut;
    }
    for (char ch : s) {
        if (cnt[ch] > 0) {
            --cnt[ch];
            cout << ch;
        }
    }
    cout << '\n';

    return 0;
}