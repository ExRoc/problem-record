#include <bits/stdc++.h>
using namespace std;

struct Node {
    int len, preI, preJ, preK;

    Node() { len = preI = preJ = preK = 0; }

    Node(int len, int preI, int preJ, int preK)
        : len(len), preI(preI), preJ(preJ), preK(preK) {}

    bool operator<(const Node& other) const { return false; }
};

struct Idx {
    int i, j, k;

    Idx(int i, int j, int k) : i(i), j(j), k(k) {}

    bool operator<(const Idx& other) const {
        return i == other.i ? (j == other.j ? k < other.k : j < other.j)
                            : i < other.i;
    }
};

int tenBit(int x, int m) {
    int ten = 1;
    if (x == 0) {
        return 10;
    }
    while (x != 0) {
        x /= 10;
        ten = ten * 10 % m;
    }
    return ten;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<vector<vector<Node>>> dp(n + 1,
                                    vector<vector<Node>>(m, vector<Node>(m)));
    set<Idx> st;
    dp[0][0][0] = Node(0, 0, 0, 0);
    st.insert(Idx(0, 0, 0));
    int idxI, idxJ, idxK;
    idxI = idxJ = idxK = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        int ten = tenBit(a[i], m);
        set<Idx> stTmp;
        for (Idx idx : st) {
            int preI = idx.i;
            int preJ = idx.j;
            int preK = idx.k;
            int j = (preJ + a[i]) % m;
            int k = (preK * ten + a[i]) % m;
            if (dp[i][j][k].len < dp[preI][preJ][preK].len + 1) {
                dp[i][j][k] =
                    Node(dp[preI][preJ][preK].len + 1, preI, preJ, preK);
                if (j == k && dp[idxI][idxJ][idxK].len < dp[i][j][k].len) {
                    idxI = i;
                    idxJ = j;
                    idxK = k;
                }
                stTmp.insert(Idx(i, j, k));
            }
        }
        st.insert(stTmp.begin(), stTmp.end());
    }
    stack<Node> stackNodes;
    stackNodes.push(Node(dp[idxI][idxJ][idxK].len, idxI, idxJ, idxK));
    while (idxI != 0) {
        Node nodeTmp = dp[idxI][idxJ][idxK];
        stackNodes.push(nodeTmp);
        idxI = nodeTmp.preI;
        idxJ = nodeTmp.preJ;
        idxK = nodeTmp.preK;
    }
    stackNodes.pop();
    cout << stackNodes.size() << '\n';
    while (!stackNodes.empty()) {
        Node nodeTmp = stackNodes.top();
        stackNodes.pop();
        cout << a[nodeTmp.preI] << " ";
    }

    return 0;
}