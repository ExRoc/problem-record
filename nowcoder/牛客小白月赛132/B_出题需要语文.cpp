#include <bits/stdc++.h>
using namespace std;

struct Node {
    int idx, quality;

    Node() {}

    Node(int idx, int quality) : idx(idx), quality(quality) {}

    bool operator<(const Node& other) const { return quality > other.quality; }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<Node>> vct(6, vector<Node>());
    for (int i = 1; i <= n; ++i) {
        char ch;
        int quality;
        cin >> ch >> quality;
        vct[ch - 'A'].push_back(Node(i, quality));
    }
    for (int i = 0; i < 6; ++i) {
        sort(vct[i].begin(), vct[i].end());
    }
    vector<int> ans(6, 0);
    bool flag = true;
    int sum = 0;
    for (int i = 0; i < 6; ++i) {
        if (vct[i].empty()) {
            flag = false;
            break;
        }
        if (vct[i][0].quality < 60) {
            flag = false;
            break;
        }
        ans[i] = vct[i][0].idx;
        sum += vct[i][0].quality;
    }
    if (!flag) {
        cout << -1 << '\n';
        return 0;
    }
    if (sum < 70 * 6) {
        cout << -1 << '\n';
        return 0;
    }
    for (int x : ans) {
        cout << x << " ";
    }
    cout << '\n';

    return 0;
}