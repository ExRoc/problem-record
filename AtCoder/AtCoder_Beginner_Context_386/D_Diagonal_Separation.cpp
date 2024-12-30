#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
struct Node {
    int x, y;
    char ch;
};

bool operator<(const Node& a, const Node& b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

int n, m;
Node node[maxn];

bool judge() {
    int lastIdx = n;
    sort(node, node + m);
    for (int i = 0; i < m; ++i) {
        if (node[i].ch == 'W') {
            lastIdx = min(lastIdx, node[i].y - 1);
            continue;
        }
        if (node[i].y > lastIdx) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> node[i].x >> node[i].y >> node[i].ch;
    }
    cout << (judge() ? "Yes" : "No") << endl;

    return 0;
}
