#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 500 + 100;
int n, k;
int num[maxn], idx[maxn], mx[maxn];
vector<pair<int, int>> ans;

bool judgeEnd() {
    for (int i = 1; i <= n; ++i) {
        mx[i] = max(mx[i - 1], num[i]);
    }
    for (int i = k + 1; i <= n; ++i) {
        if (mx[i - k] > num[i]) {
            return false;
        }
    }
    return true;
}

void print() {
    if (!ans.empty()) {
        cout << ans.back().first << " " << ans.back().second << endl;
    }
    for (int i = 1; i <= n; ++i) {
        cout << num[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
        idx[num[i]] = i;
    }
    while (!judgeEnd()) {
        bool flag = false;
        for (int i = n - 1; i >= 1; --i) {
            for (int j = i + 1; j <= n; ++j) {
                if (idx[i] - idx[j] >= k) {
                    ans.push_back({idx[j], idx[i]});
                    swap(num[idx[i]], num[idx[j]]);
                    swap(idx[i], idx[j]);
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for (pair<int, int> p : ans) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
