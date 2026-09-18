#include <bits/stdc++.h>
using namespace std;

bool add(map<int, vector<int>>& mod, vector<int>& ans, int x) {
    if (mod[x].empty()) {
        return false;
    }
    ans.push_back(mod[x].back());
    mod[x].pop_back();
    return true;
}

// 121212121212...1/2
void add(map<int, vector<int>>& mod, vector<int>& ans, int one, int two) {
    bool addOne = true;
    while (true) {
        if (addOne) {
            if (mod[one].empty()) {
                break;
            } else {
                add(mod, ans, one);
            }
        } else {
            if (mod[two].empty()) {
                break;
            } else {
                add(mod, ans, two);
            }
        }
        addOne = !addOne;
    }
    if (!mod[one].empty()) {
        add(mod, ans, one);
        if (!mod[one].empty() || !mod[two].empty()) {
            ans.clear();
        }
        return;
    }
    if (!mod[two].empty()) {
        add(mod, ans, two);
        if (!mod[one].empty() || !mod[two].empty()) {
            ans.clear();
        }
        return;
    }
}

void solve0(map<int, vector<int>>& mod, vector<int>& ans) {
    if (mod[2].size() > mod[1].size()) {
        // 200000021212121212121……1/2
        add(mod, ans, 2);
        while (!mod[0].empty()) {
            add(mod, ans, 0);
        }
        add(mod, ans, 2, 1);
        return;
    }
    //      100000012121212121212……1/2
    if (!add(mod, ans, 1)) {
        ans.clear();
        return;
    }
    while (!mod[0].empty()) {
        add(mod, ans, 0);
    }
    add(mod, ans, 1, 2);
}

// 如果和为 1
//      规则：
//      00000000000012121212……1/2
void solve1(map<int, vector<int>>& mod, vector<int>& ans) {
    while (!mod[0].empty()) {
        add(mod, ans, 0);
    }
    add(mod, ans, 1, 2);
}

// 如果和为 2，规则：
//      0000000212121212121……1/2
void solve2(map<int, vector<int>>& mod, vector<int>& ans) {
    while (!mod[0].empty()) {
        add(mod, ans, 0);
    }
    add(mod, ans, 2, 1);
}

int main() {
#ifdef ExRoc
    freopen("test.txt", "r", stdin);
#endif  // ExRoc
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, vector<int>> mod;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            mod[a % 3].push_back(a);
            sum = (sum + a) % 3;
        }
        vector<int> ans;
        if (sum == 0) {
            solve0(mod, ans);
        } else if (sum == 1) {
            solve1(mod, ans);
        } else {
            solve2(mod, ans);
        }
        if (ans.empty()) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        for (int x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}