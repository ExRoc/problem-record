#include <bits/stdc++.h>
using namespace std;

void addI(vector<int>& cnt, int x, int s, int& idxI, int& idxE) {
    if (idxI >= x) {
        return;
    }
    ++cnt[idxI];
    ++idxI;
    if (cnt[idxI - 1] == s) {
        idxE = idxI;
    }
}

void addE(vector<int>& cnt, int x, int s, int& idxI, int& idxE) {
    if (idxE >= idxI) {
        return;
    }
    ++cnt[idxE];
    if (cnt[idxE] == s) {
        ++idxE;
    }
}

int solve(int cntA, const string& AEI, int x, int s) {
    int idxI = 0;
    int idxE = 0;
    vector<int> cnt(x, 0);
    for (char ch : AEI) {
        if (ch == 'I') {
            addI(cnt, x, s, idxI, idxE);
        } else if (ch == 'E') {
            addE(cnt, x, s, idxI, idxE);
        } else {
            if (cntA > 0) {
                addI(cnt, x, s, idxI, idxE);
                --cntA;
            } else {
                addE(cnt, x, s, idxI, idxE);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < x; ++i) {
        ans += cnt[i];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, x, s;
        cin >> n >> x >> s;
        string AEI;
        cin >> AEI;
        int cntA = 0;
        for (char ch : AEI) {
            if (ch == 'A') {
                ++cntA;
            }
        }
        int high = cntA;
        int low = 0;
        while (high - low > 2) {
            int mid1 = low + (high - low) / 3;
            int mid2 = high - (high - low) / 3;
            if (solve(mid1, AEI, x, s) < solve(mid2, AEI, x, s)) {
                low = mid1;
            } else {
                high = mid2;
            }
        }
        int ans = 0;
        for (int i = low; i <= high; ++i) {
            ans = max(ans, solve(i, AEI, x, s));
        }
        cout << ans << '\n';
    }

    return 0;
}