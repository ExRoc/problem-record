#include <bits/stdc++.h>
using namespace std;

bool judge(const string& S, int l, int r) {
    vector<int> times;
    times.push_back(0);
    for (int i = l; i <= r; ++i) {
        if (S[i] == 'T') {
            ++times.back();
            continue;
        }
        if (times.back() == 0) {
            continue;
        }
        times.push_back(0);
    }
    while (!times.empty() && times.back() == 0) {
        times.pop_back();
    }
    if (times.size() > 2) {
        return false;
    }
    for (int t : times) {
        if (t >= 6) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string S;
    cin >> S;
    S = ' ' + S;
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1];
        if (S[i] == 'T') {
            ++sum[i];
        }
        if (i >= 24 && sum[i] - sum[i - 24] < 10) {
            cout << "No" << '\n' << i << '\n';
            return 0;
        }
        if (i >= 168 && sum[i] - sum[i - 168] < 77) {
            cout << "No" << '\n' << i << '\n';
            return 0;
        }
        if (i >= 24 && !judge(S, i - 24 + 1, i)) {
            cout << "No" << '\n' << i << '\n';
            return 0;
        }
    }
    cout << "Yes" << '\n';

    return 0;
}