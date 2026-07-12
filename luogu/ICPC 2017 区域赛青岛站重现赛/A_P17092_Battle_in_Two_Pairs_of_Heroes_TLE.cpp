#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long hashCode;

    Node() {}

    Node(int who, int a1, int a2, int b1, int b2) {
        hashCode = who * 100000000 + a1 * 1000000 + a2 * 10000 + b1 * 100 + b2;
    }

    bool operator==(const Node& other) const {
        return hashCode == other.hashCode;
    }
};

namespace std {
template <>
struct hash<Node> {
    size_t operator()(const Node& p) const { return p.hashCode; }
};
}  // namespace std

unordered_map<Node, char> dp;
vector<vector<int>> aToB(2, vector<int>(2));
vector<vector<int>> bToA(2, vector<int>(2));

int dfs(int who, int a1, int a2, int b1, int b2) {
    Node node = Node(who, a1, a2, b1, b2);
    if (dp.find(node) != dp.end()) {
        return dp[node];
    }
    if (a1 == 0 && a2 == 0) {
        return dp[node] = 1;
    }
    if (b1 == 0 && b2 == 0) {
        return dp[node] = 0;
    }
    if (who == 0) {
        if (a1 > 0 && a2 > 0) {
            // 将 B1 的生命值减少 a11​+a21​；
            if (b1 > 0 &&
                dfs(1, a1, a2, max(0, b1 - aToB[0][0] - aToB[1][0]), b2) == 0) {
                return dp[node] = 0;
            }
            // 将 B2 的生命值减少 a12​+a22​；
            if (b2 > 0 &&
                dfs(1, a1, a2, b1, max(0, b2 - aToB[0][1] - aToB[1][1])) == 0) {
                return dp[node] = 0;
            }
            // 将 B1 的生命值减少 a11​，同时将 B2
            // 的生命值减少 a22​；
            if (b1 > 0 && b2 > 0 &&
                dfs(1, a1, a2, max(0, b1 - aToB[0][0]),
                    max(0, b2 - aToB[1][1])) == 0) {
                return dp[node] = 0;
            }
            // 将 B1 的生命值减少 a21​，同时将 B2
            // 的生命值减少 a12​。
            if (b1 > 0 && b2 > 0 &&
                dfs(1, a1, a2, max(0, b1 - aToB[1][0]),
                    max(0, b2 - aToB[0][1])) == 0) {
                return dp[node] = 0;
            }
            return dp[node] = 1;
        } else if (a1 > 0) {
            if (b1 > 0 && dfs(1, a1, a2, max(0, b1 - aToB[0][0]), b2) == 0) {
                return dp[node] = 0;
            }
            if (b2 > 0 && dfs(1, a1, a2, b1, max(0, b2 - aToB[0][1])) == 0) {
                return dp[node] = 0;
            }
            return dp[node] = 1;
        }
        if (b1 > 0 && dfs(1, a1, a2, max(0, b1 - aToB[1][0]), b2) == 0) {
            return dp[node] = 0;
        }
        if (b2 > 0 && dfs(1, a1, a2, b1, max(0, b2 - aToB[1][1])) == 0) {
            return dp[node] = 0;
        }
        return dp[node] = 1;
    }
    if (b1 > 0 && b2 > 0) {
        // 将 A1 的生命值减少 b11​+b21​；
        if (a1 > 0 &&
            dfs(0, max(0, a1 - bToA[0][0] - bToA[1][0]), a2, b1, b2) == 1) {
            return dp[node] = 1;
        }
        // 将 A2 的生命值减少 b12​+b22​；
        if (a2 > 0 &&
            dfs(0, a1, max(0, a2 - bToA[0][1] - bToA[1][1]), b1, b2) == 1) {
            return dp[node] = 1;
        }
        // 将 A1 的生命值减少 b11​，同时将 A2
        // 的生命值减少 b22​；
        if (a1 > 0 && a2 > 0 &&
            dfs(0, max(0, a1 - bToA[0][0]), max(0, a2 - bToA[1][1]), b1, b2) ==
                1) {
            return dp[node] = 1;
        }
        // 将 A1 的生命值减少 b21​，同时将 A2
        // 的生命值减少 b12​。
        if (a1 > 0 && a2 > 0 &&
            dfs(0, max(0, a1 - bToA[1][0]), max(0, a2 - bToA[0][1]), b1, b2) ==
                1) {
            return dp[node] = 1;
        }
        return dp[node] = 0;
    } else if (b1 > 0) {
        if (a1 > 0 && dfs(0, max(0, a1 - bToA[0][0]), a2, b1, b2) == 1) {
            return dp[node] = 1;
        }
        if (a2 > 0 && dfs(0, a1, max(0, a2 - bToA[0][1]), b1, b2) == 1) {
            return dp[node] = 1;
        }
        return dp[node] = 0;
    }
    if (a1 > 0 && dfs(0, max(0, a1 - bToA[1][0]), a2, b1, b2) == 1) {
        return dp[node] = 1;
    }
    if (a2 > 0 && dfs(0, a1, max(0, a2 - bToA[1][1]), b1, b2) == 1) {
        return dp[node] = 1;
    }
    return dp[node] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp.reserve(10000000);
    int T;
    cin >> T;
    while (T--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        dp.clear();
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                cin >> aToB[i][j];
            }
        }
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                cin >> bToA[i][j];
            }
        }
        int win = dfs(1, a1, a2, b1, b2);
        if (win == 0) {
            cout << "Alice wins" << '\n';
            continue;
        }
        win = dfs(0, a1, a2, b1, b2);
        if (win == 1) {
            cout << "Bob wins" << '\n';
            continue;
        }
        cout << "It depends" << '\n';
    }

    return 0;
}