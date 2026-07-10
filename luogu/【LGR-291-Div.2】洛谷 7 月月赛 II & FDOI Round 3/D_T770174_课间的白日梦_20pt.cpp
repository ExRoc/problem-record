#include <bits/stdc++.h>
using namespace std;

struct Node {
    int ans;
    int preI, preJ;
    vector<int> mnIdxs, mxIdxs;

    Node() : ans(0), preI(-1), preJ(-1), mnIdxs(26, -1), mxIdxs(26, -1) {}

    void calAns() {
        ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += mxIdxs[i] - mnIdxs[i];
        }
    }

    void setPre(int preI, int preJ) {
        this->preI = preI;
        this->preJ = preJ;
    }
};

Node merge(const Node& node1, int len1, const Node& node2, int len2,
           const vector<vector<int>>& sum, int n, int idx) {
    Node node;
    for (int i = 0; i < 26; ++i) {
        bool leftCh = (sum[n][i] - sum[idx][i] > 0);
        if (node1.mnIdxs[i] == -1 && node2.mnIdxs[i] == -1) {
            continue;
        }
        if (node1.mnIdxs[i] == -1) {
            node.mxIdxs[i] = node2.mxIdxs[i] - len1;
            if (leftCh) {
                node.mnIdxs[i] = 0;
            } else {
                node.mnIdxs[i] = node2.mnIdxs[i] - len1;
            }
            continue;
        }
        if (node2.mnIdxs[i] == -1) {
            node.mxIdxs[i] = node1.mxIdxs[i] + len2;
            if (leftCh) {
                node.mnIdxs[i] = 0;
            } else {
                node.mnIdxs[i] = node1.mnIdxs[i] + len2;
            }
            continue;
        }
        node.mxIdxs[i] = node1.mxIdxs[i] + len2;
        if (leftCh) {
            node.mnIdxs[i] = 0;
        } else {
            node.mnIdxs[i] = node2.mnIdxs[i] - len1;
        }
    }
    node.calAns();
    return node;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    string S;
    cin >> S;
    S = ' ' + S;
    vector<vector<int>> sum(n + 1, vector<int>(26, 0));
    vector<int> firstIdx(26, -1);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1];
        ++sum[i][S[i] - 'a'];
        if (firstIdx[S[i] - 'a'] == -1) {
            firstIdx[S[i] - 'a'] = i;
        }
    }
    vector<vector<Node>> dp(n + 1, vector<Node>(k + 1));
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = dp[i - 1][1];
        dp[i][1].mxIdxs[S[i] - 'a'] = i;
        if (sum[n][S[i] - 'a'] - sum[i][S[i] - 'a'] != 0) {
            dp[i][1].mnIdxs[S[i] - 'a'] = 0;
        } else if (dp[i][1].mnIdxs[S[i] - 'a'] == -1) {
            dp[i][1].mnIdxs[S[i] - 'a'] = i;
        } else {
            dp[i][1].mnIdxs[S[i] - 'a'] = firstIdx[S[i] - 'a'];
        }
        dp[i][1].calAns();
        int topJ = min(k, i);
        for (int j = 2; j <= topJ; ++j) {
            Node tmp;
            for (int kk = i; kk > j - 1; --kk) {
                int ch = S[kk] - 'a';
                if (tmp.mxIdxs[ch] == -1) {
                    tmp.mnIdxs[ch] = tmp.mxIdxs[ch] = kk;
                } else {
                    tmp.mnIdxs[ch] = kk;
                }
                Node node = merge(dp[kk - 1][j - 1], kk - 1, tmp, i - kk + 1,
                                  sum, n, i);
                if (node.ans > dp[i][j].ans) {
                    dp[i][j] = node;
                    dp[i][j].setPre(kk - 1, j - 1);
                }
            }
            int preI = dp[i][j].preI;
            int preJ = dp[i][j].preJ;
        }
    }

    cout << dp[n][k].ans << '\n';
    if (dp[n][k].ans == 0) {
        for (int i = 1; i < k; ++i) {
            cout << S[i] << " ";
        }
        for (int i = k; i <= n; ++i) {
            cout << S[i];
        }
        cout << '\n';
        return 0;
    }

    set<int> idxs;
    int i = n;
    int j = k;
    while (i != -1) {
        idxs.insert(i);
        Node node = dp[i][j];
        i = node.preI;
        j = node.preJ;
    }
    for (int i = 1; i <= n; ++i) {
        cout << S[i];
        if (idxs.find(i) != idxs.end()) {
            cout << ' ';
        }
    }
    cout << '\n';

    return 0;
}