#include <bits/stdc++.h>
using namespace std;

struct Node {
    int cnt, idx;

    Node() {}

    Node(int cnt, int idx) : cnt(cnt), idx(idx) {}

    bool operator<(const Node& other) const {
        return cnt == other.cnt ? idx < other.idx : cnt > other.cnt;
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
        set<int> emptyIdx;
        for (int i = 0; i < x; ++i) {
            emptyIdx.insert(i);
        }
        vector<int> cnt(x, 0);
        vector<int> freeACnt(x, 0);
        set<Node> notEmptyNotFullIdx;
        set<Node> containsFreeAIdx;
        set<Node> notFullIdx;
        for (int i = 0; i < x; ++i) {
            notFullIdx.insert(Node(0, i));
        }
        for (char ch : AEI) {
            if (ch == 'I') {
                if (!emptyIdx.empty()) {
                    int idx = *emptyIdx.begin();
                    emptyIdx.erase(idx);
                    ++cnt[idx];
                    notFullIdx.erase(Node(0, idx));
                    if (cnt[idx] < s) {
                        notEmptyNotFullIdx.insert(Node(1, idx));
                        notFullIdx.insert(Node(1, idx));
                    }
                    continue;
                }
            } else if (ch == 'E') {
                if (!notEmptyNotFullIdx.empty()) {
                    Node oldNode = *notEmptyNotFullIdx.begin();
                    Node newNode = Node(oldNode.cnt + 1, oldNode.idx);
                    ++cnt[oldNode.idx];
                    notEmptyNotFullIdx.erase(oldNode);
                    if (newNode.cnt < s) {
                        notEmptyNotFullIdx.insert(newNode);
                    }
                    if (containsFreeAIdx.find(oldNode) !=
                        containsFreeAIdx.end()) {
                        containsFreeAIdx.erase(oldNode);
                        containsFreeAIdx.insert(newNode);
                    }
                    notFullIdx.erase(oldNode);
                    if (newNode.cnt < s) {
                        notFullIdx.insert(newNode);
                    }
                    continue;
                }
                if (!emptyIdx.empty() && !containsFreeAIdx.empty()) {
                    Node oldNode = *containsFreeAIdx.begin();
                    Node newNode = Node(oldNode.cnt - 1, oldNode.idx);
                    int eIdx = *emptyIdx.begin();
                    emptyIdx.erase(eIdx);
                    --cnt[oldNode.idx];
                    cnt[eIdx] += 2;
                    --freeACnt[oldNode.idx];
                    notEmptyNotFullIdx.erase(oldNode);
                    if (newNode.cnt > 0 && newNode.cnt < s) {
                        notEmptyNotFullIdx.insert(newNode);
                    }
                    if (cnt[eIdx] < s) {
                        notEmptyNotFullIdx.insert(Node(cnt[eIdx], eIdx));
                    }
                    containsFreeAIdx.erase(oldNode);
                    if (freeACnt[oldNode.idx] != 0) {
                        containsFreeAIdx.insert(newNode);
                    }
                    notFullIdx.erase(oldNode);
                    if (newNode.cnt < s) {
                        notFullIdx.insert(newNode);
                    }
                    notFullIdx.erase(Node(0, eIdx));
                    if (cnt[eIdx] < s) {
                        notFullIdx.insert(Node(cnt[eIdx], eIdx));
                    }
                    continue;
                }
            } else if (ch == 'A') {
                if (!notFullIdx.empty()) {
                    Node oldNode = *notFullIdx.begin();
                    Node newNode = Node(oldNode.cnt + 1, oldNode.idx);
                    containsFreeAIdx.erase(oldNode);
                    if (emptyIdx.find(oldNode.idx) == emptyIdx.end()) {
                        ++freeACnt[oldNode.idx];
                        containsFreeAIdx.insert(newNode);
                    } else {
                        emptyIdx.erase(oldNode.idx);
                    }
                    ++cnt[oldNode.idx];
                    notEmptyNotFullIdx.erase(oldNode);
                    if (newNode.cnt > 0 && newNode.cnt < s) {
                        notEmptyNotFullIdx.insert(newNode);
                    }
                    notFullIdx.erase(oldNode);
                    if (newNode.cnt < s) {
                        notFullIdx.insert(newNode);
                    }
                    continue;
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
