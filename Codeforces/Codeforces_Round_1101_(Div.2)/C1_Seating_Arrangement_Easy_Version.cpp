#include <bits/stdc++.h>
using namespace std;

struct Node {
    char type;
    bool canMove;

    Node() {}

    Node(char type) : type(type), canMove(false) {}

    Node(char type, bool canMove) : type(type), canMove(canMove) {}

    bool operator<(const Node& other) const {
        return type == other.type ? canMove < other.canMove : type < other.type;
    }
};

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
        vector<map<Node, int>> cntMap(x);
        vector<int> cnt(x);
        for (char ch : AEI) {
            if (ch == 'I') {
                for (int i = 0; i < x; ++i) {
                    if (cnt[i] == 0) {
                        ++cnt[i];
                        ++cntMap[i][Node('I')];
                        break;
                    }
                }
            } else if (ch == 'E') {
                bool flag = false;
                for (int i = 0; i < x; ++i) {
                    if (cnt[i] > 0 && cnt[i] < s) {
                        ++cnt[i];
                        ++cntMap[i][Node('E')];
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    continue;
                }
                int idx1 = -1;
                int idx2 = -1;
                for (int i = 0; i < x; ++i) {
                    if (cntMap[i][Node('A', true)] != 0) {
                        idx1 = i;
                    }
                    if (cnt[i] == 0) {
                        idx2 = i;
                    }
                }
                if (idx1 != -1 && idx2 != -1) {
                    --cntMap[idx1][Node('A', true)];
                    --cnt[idx1];
                    cnt[idx2] += 2;
                    ++cntMap[idx2][Node('A')];
                    ++cntMap[idx2][Node('E')];
                }
            } else if (ch == 'A') {
                for (int i = 0; i < x; ++i) {
                    if (cnt[i] < s) {
                        if (cnt[i] == 0) {
                            ++cntMap[i][Node('A')];
                        } else {
                            ++cntMap[i][Node('A', true)];
                        }
                        ++cnt[i];
                        break;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < x; ++i) {
            ans += cnt[i];
        }
        cout << ans << '\n';
    }

    return 0;
}